#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: monotone.sh,v 1.6 2010/03/12 09:27:18 jmmv Exp $
#
# Copyright (c) 2010 The NetBSD Foundation, Inc.
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
# ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
# TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
# BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.

#
# PROVIDE: monotone
# REQUIRE: DAEMON
#

#
# See the monotone-server(7) manual page for details on how to use and configure
# this script.
#

. /etc/rc.subr

progname=${0##*/}
saved_args="${@}"

# Settings from package build.  Cannot be modified after installation.
digest_bin="@DIGEST@"
monotone_bin="@MONOTONE@"
monotone_group="@MONOTONE_GROUP@"
monotone_logfile="@MONOTONE_LOGFILE@"
monotone_user="@MONOTONE_USER@"
pkg_sysconfdir="@PKG_SYSCONFDIR@"

# Settings from system configuration.
monotone_default_home=$(grep "^${monotone_user}:" /etc/passwd | cut -d : -f 6)
monotone_default_keyname="monotone@$(hostname)"
: ${monotone_home:=${monotone_default_home}}

# Settings derived from the above.
monotone_db="${monotone_home}/monotone.db"
monotone_keysdir="${pkg_sysconfdir}/keys"
monotone_passphrases="${pkg_sysconfdir}/passphrases"
monotone_flags="--db='${monotone_db}' \
                --norc \
                --confdir='${pkg_sysconfdir}' \
                --keydir='${monotone_keysdir}' \
                --rcfile='${pkg_sysconfdir}/monotonerc'"

# rc.d(8) script boilerplate.
name="monotone"
rcvar="${name}"
rcvar_manpage="monotone-server(7)"
command="${monotone_bin}"
command_args="${monotone_flags} serve >>${monotone_logfile} 2>&1 &"
monotone_chdir="${monotone_home}"
required_files="${pkg_sysconfdir}/monotonerc \
                ${pkg_sysconfdir}/read-permissions \
                ${pkg_sysconfdir}/write-permissions"
start_precmd="monotone_start_precmd"
extra_commands="init genkey migrate read"
genkey_cmd="monotone_genkey"
init_cmd="monotone_init"
read_cmd="monotone_read"

info_no_log() {
	echo "${progname}: ${*}"
}

info() {
	log "${@}"
	info_no_log "${@}"
}

log() {
	require_logfile
	echo "${@}" >>"${monotone_logfile}"
}

run_monotone() {
	log su - "${monotone_user}" -c "'${command}' ${monotone_flags} ${*}"
	su - "${monotone_user}" -c "'${command}' ${monotone_flags} ${*}" || \
	    err 1 "Execution of monotone '${*}' failed"
}

require_logfile() {
	test -f "${monotone_logfile}" || \
	    err 1 "'${monotone_logfile}' is missing; use the 'init'" \
	    "subcommand to initialize the server"
}

require_server_initialized() {
	test -f "${monotone_db}" || \
	    err 1 "'${monotone_db}' is missing; use the 'init' subcommand" \
	    "to initialize the server"
}

require_server_key() {
	test -f "${monotone_passphrases}" || \
	    err 1 "'${monotone_passphrases}' is missing; use the" \
	    "'genkey' subcommand to generate a server key"
}

monotone_genkey() {
	set -- ${saved_args}; shift
	local keyname="${1:-${monotone_default_keyname}}"

	test -f "${monotone_passphrases}" && \
	    err 1 "${monotone_passphrases} already exists"

	if [ ! -d "${monotone_keysdir}" ]; then
		info "Creating keys directory '${monotone_keysdir}'"
		mkdir "${monotone_keysdir}" || \
		    err 1 "failed to create '${monotone_keysdir}'"
	else
		info "Resetting permissions of '${monotone_keysdir}'"
	fi
	chmod 700 "${monotone_keysdir}"
	chown "${monotone_user}:${monotone_group}" "${monotone_keysdir}"

	require_server_initialized

	info "Creating key '${keyname}'"

	keypass=$(dd if=/dev/urandom bs=1024 count=100 | ${digest_bin} sha512)

	touch "${monotone_passphrases}"
	chmod 600 "${monotone_passphrases}"
	chown "${monotone_user}:${monotone_group}" "${monotone_passphrases}"
	echo "${keyname} \"${keypass}\"" >>"${monotone_passphrases}"

	run_monotone genkey "${keyname}" <<EOF
${keypass}
${keypass}
EOF
}

monotone_init() {
	test -f "${monotone_db}" && \
	    err 1 "database '${monotone_db}' already initialized"

	if [ ! -f "${monotone_logfile}" ]; then
		info_no_log "Creating log file '${monotone_logfile}'"
		touch "${monotone_logfile}" || \
		    err 1 "failed to create '${monotone_logfile}'"
	else
		info_no_log "Resetting permissions of '${monotone_logfile}'"
	fi
	chmod 600 "${monotone_logfile}"
	chown "${monotone_user}:${monotone_group}" "${monotone_logfile}"

	if [ ! -d "${monotone_home}" ]; then
		info "Creating home directory '${monotone_home}'"
		mkdir "${monotone_home}" || \
		    err 1 "failed to create '${monotone_home}'"
	else
		info "Resetting permissions of '${monotone_home}'"
	fi
	chmod 700 "${monotone_home}"
	chown "${monotone_user}:${monotone_group}" "${monotone_home}"

	info "Initializing database '${monotone_db}'"
	run_monotone db init
	chown "${monotone_user}:${monotone_group}" "${monotone_db}"
	chmod 600 "${monotone_db}"

	info "All done!"
	info "Use the 'genkey' subcommand to create a new server key"
	info "Use the 'read' subcommand to import existing user public keys"
}

monotone_migrate() {
	require_server_initialized

	run_monotone db migrate
}

monotone_read() {
	set -- ${saved_args}; shift

	require_server_initialized

	if [ ${#} -gt 0 ]; then
		while [ ${#} -gt 0 ]; do
			info "Importing keys from '${1}' into '${monotone_db}'"
			run_monotone read <"${1}"
			shift
		done
	else
			info "Importing keys from stdin into '${monotone_db}'"
			run_monotone read
	fi
}

monotone_start_precmd() {
	require_server_initialized
	require_server_key
	log "Server started on $(date)"
	log "${command}" "${command_args}"
}

load_rc_config "${name}"
run_rc_command "${1}"
