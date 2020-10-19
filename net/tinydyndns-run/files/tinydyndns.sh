#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: tinydyndns.sh,v 1.2 2020/10/19 07:15:55 schmonz Exp $
#
# @PKGNAME@ script to control tinydyndns (dynamic DNS service).
#

# PROVIDE: tinydyndns named
# REQUIRE: NETWORKING mountcritremote syslogd
# BEFORE:  DAEMON

name="tinydyndns"

# User-settable rc.conf variables and their default values:
: ${tinydyndns_postenv:=""}
: ${tinydyndns_ip:="0.0.0.0"}
: ${tinydyndns_datalimit:="300000"}
: ${tinydyndns_autodata:="YES"}
: ${tinydyndns_autocdb:="YES"}
: ${tinydyndns_log:="YES"}
: ${tinydyndns_logcmd:="logger -t nbtinydyn/dns -p daemon.info"}
: ${tinydyndns_nologcmd:="@PREFIX@/bin/multilog -*"}

tinydyn_data="@PKG_SYSCONFDIR@/data"
tinydyn_domain="@PKG_SYSCONFDIR@/domain"
tinydyn_passwd="@PKG_SYSCONFDIR@/passwd"

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

rcvar=${name}
required_files="${tinydyn_domain} ${tinydyn_passwd}"
command="@PREFIX@/bin/tinydns"
procname=nb${name}
start_precmd="tinydyndns_precmd"
extra_commands="rebuild"
rebuild_cmd="tinydyndns_rebuild"

tinydyndns_precmd() {
	if [ -f /etc/rc.subr ] && ! checkyesno tinydyndns_log; then
		tinydyndns_logcmd=${tinydyndns_nologcmd}
	fi
	if [ -f /etc/rc.subr ] && checkyesno tinydyndns_autodata; then
		tinydyndns_needdata && tinydyndns_initdata
	else
		required_files="${tinydyn_data} ${required_files}"
	fi
	if [ -f /etc/rc.subr ] && checkyesno tinydyndns_autocdb; then
		tinydyndns_needcdb && tinydyndns_rebuild
	else
		required_files="${tinydyn_data}.cdb ${required_files}"
	fi
	command="@PREFIX@/bin/pgrphack @SETENV@ - ${tinydyndns_postenv} \
ROOT=@PKG_SYSCONFDIR@ \
IP=${tinydyndns_ip} \
@PREFIX@/bin/envuidgid @TINYDYN_USER@ \
@PREFIX@/bin/softlimit -d ${tinydyndns_datalimit} \
@PREFIX@/bin/argv0 @PREFIX@/bin/tinydns ${procname} \
</dev/null 2>&1 | \
@PREFIX@/bin/pgrphack @PREFIX@/bin/setuidgid @DJBDNS_LOG_USER@ ${tinydyndns_logcmd}"
	command_args="&"
	rc_flags=""
}

tinydyndns_needdata() {
	[ ! -f "${tinydyn_data}" ]
}

tinydyndns_initdata() {
	@ECHO@ "Auto-creating ${tinydyn_data}."
	if [ ${tinydyndns_ip} = "0.0.0.0" ]; then
		@ECHO@ >&2 "ERROR: set tinydyndns_ip in rc.conf"
		exit 1
	fi
	_domain=$(@HEAD@ -1 ${tinydyn_domain})
	if [ -z "${_domain}" ]; then
		@ECHO@ >&2 "ERROR: write the domain to ${tinydyn_domain}"
		exit 2
	fi
	@CAT@ >${tinydyn_data}.tmp <<EOF
.${_domain}:${tinydyndns_ip}:a:259200
+${_domain}:${tinydyndns_ip}:86400
EOF
	@MV@ -f ${tinydyn_data}.tmp ${tinydyn_data}
	@CHOWN@ @TINYDYN_USER@ ${tinydyn_data}
	@CHMOD@ 644 ${tinydyn_data}
}

tinydyndns_needcdb() {
	_src=${tinydyn_data}
	_dst=${tinydyn_data}.cdb
	[ -f "${_src}" -a "${_src}" -nt "${_dst}" ] || [ ! -f "${_dst}" ]
}

tinydyndns_rebuild() {
	@ECHO@ "Rebuilding ${tinydyn_data}.cdb."
	cd @PKG_SYSCONFDIR@ && @PREFIX@/bin/tinydns-data
	_domain=$(@HEAD@ -1 ${tinydyn_domain})
	@CUT@ -d: -f1 < ${tinydyn_passwd} \
		| @SED@ -e "s|\$|.${_domain}|" \
		| @XARGS@ @PREFIX@/bin/tinydyndns-data add
	@CHOWN@ @TINYDYN_USER@ ${tinydyn_data}.cdb
	@CHMOD@ 644 ${tinydyn_data}.cdb
}

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO_N@ " ${name}"
	tinydyndns_precmd
	eval ${command} ${tinydyndns_flags} ${command_args}
fi
