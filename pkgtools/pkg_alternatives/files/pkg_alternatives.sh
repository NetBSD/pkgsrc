#!@SH@
#
# $NetBSD: pkg_alternatives.sh,v 1.7 2012/06/13 15:35:32 jperkin Exp $
#
# pkg_alternatives - Generic wrappers for programs with similar interfaces
# Copyright (c) 2005 Julio M. Merino Vidal <jmmv@NetBSD.org>
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in
#    the documentation and/or other materials provided with the
#    distribution.
# 3. Neither the name of author nor the names of its contributors may
#    be used to endorse or promote products derived from this software
#    without alternative prior written permission.
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

Conf_Dir=@CONFDIR@@PREFIX@
Data_Dir=@DATADIR@
Db_Dir=@DBDIR@@PREFIX@
Filter=
Filter_Read=no
Prefix=@PREFIX@
Prog_Name=${0##*/}
Verbose=yes

: ${PKG_DBDIR:=@PKG_DBDIR@}
: ${PKGMANDIR:=@PKGMANDIR@}

# -------------------------------------------------------------------------

# action_auto_package package
#
# Configures the given package to be in automatic mode.  I.e., it removes
# local customizations for all related wrappers, so that only the files in
# the database are taken into account.
#
action_auto_package() {
    validate_args auto ${#} -eq 1
    validate_package ${1}
    pkg=${PKG_DBDIR}/${1}*/+ALTERNATIVES

    set -- $(cat ${pkg} | sed -e 's# #__dE/lImIt/Er__#g')
    while [ ${#} -gt 0 ]; do
        action_auto_wrapper ${1%%__dE/lImIt/Er__*}
        shift
    done
}

# -------------------------------------------------------------------------

# action_auto_wrapper wrapper
#
# Configures the given wrapper to be in automatic mode.  I.e., it removes
# local customizations so that only the files in the database are taken
# into account.
#
# wrapper is a path relative to prefix.
#
action_auto_wrapper() {
    validate_args auto ${#} -eq 1
    validate_wrapper ${1} yes

    conf=$(get_my_config)/${1}
    if [ -f ${conf} ]; then
        info "removing configuration from \`${conf}'"
        rm -f ${conf}
        rmdir_p ${conf%/*}
    else
        info "no existing configuration for \`${1}'; nothing to be done"
    fi
}

# -------------------------------------------------------------------------

# action_destroy_package
#
# Destroys the alternatives database and removes all installed wrappers.
#
action_destroy_package() {
    validate_args list ${#} -eq 0

    [ -d ${Db_Dir} ] || return 0

    wrappers=$(cd ${Db_Dir} ; find . -type f)

    for w in ${wrappers}; do
        wrapper=$(echo ${w} | sed -e 's|^./||')
        manpage=$(get_manpage ${wrapper})
        info "removing wrapper \`${wrapper}'"
        rm -f ${Prefix}/${wrapper}
        info "removing manual page \`${manpage}'"
        rm -f ${manpage}
    done

    info "removing contents of \`@DBDIR@'"
    rm -rf @DBDIR@/* 2>/dev/null
    rmdir_p @DBDIR@
}

# -------------------------------------------------------------------------

# action_destroy_wrapper
#
# Unavailable action.
#
action_destroy_wrapper() {
    err "the \`destroy' action cannot be used in wrapper mode"
}

# -------------------------------------------------------------------------

# action_list_package
#
# Lists all available packages that provide alternatives.
#
action_list_package() {
    validate_args list ${#} -eq 0

    info "looking for alternatives in \`${PKG_DBDIR}'"
    for d in ${PKG_DBDIR}/*; do
        [ -f ${d}/+ALTERNATIVES ] && echo ${d##${PKG_DBDIR}/}
    done
}

# -------------------------------------------------------------------------

# action_list_wrapper
#
# Unavailable action.
#
action_list_wrapper() {
    err "the \`list' action cannot be used in wrapper mode"
}

# -------------------------------------------------------------------------

# action_manual_package package
#
# Configures the given package to be the preferred alternative for all the
# wrappers associated to it.
#
action_manual_package() {
    validate_args manual ${#} -eq 1
    validate_package ${1}
    pkg=${PKG_DBDIR}/${1}*/+ALTERNATIVES

    set -- $(cat ${pkg} | sed -e 's# #__dE/lImIt/Er__#g')
    while [ ${#} -gt 0 ]; do
        action_manual_wrapper $(echo ${1} | sed -e 's#__dE/lImIt/Er__# #g')
        shift
    done
}

# -------------------------------------------------------------------------

# action_manual_wrapper wrapper alternative arguments
#
# Configures the given wrapper to use the specified alternative.
# If running as the administrator, the system-wide settings are changed;
# otherwise, the user-specific settings are affected.
#
# wrapper is a path relative to prefix.
# alternative is an absolute path.
#
action_manual_wrapper() {
    validate_args manual ${#} -ge 2
    validate_wrapper ${1} yes
    validate_alternative ${2}

    conf=$(get_my_config)/${1}
    info "modifying configuration from \`${conf}'"
    mkdir_p ${conf%/*}
    shift
    echo "${*}" >${conf}
}

# -------------------------------------------------------------------------

# action_rebuild_package
#
# Rebuilds the alternatives database from the package database and also
# reinstalls the wrappers (so that filter.conf takes effect).
#
action_rebuild_package() {
    validate_args list ${#} -eq 0

    action_destroy_package
    info "looking for alternatives in \`${PKG_DBDIR}'"
    for d in ${PKG_DBDIR}/*; do
        if [ -f ${d}/+ALTERNATIVES ]; then
            action_register_package ${d}/+ALTERNATIVES
        fi
    done
}

# -------------------------------------------------------------------------

# action_rebuild_wrapper
#
# Unavailable action.
#
action_rebuild_wrapper() {
    err "the \`rebuild' action cannot be used in wrapper mode"
}

# -------------------------------------------------------------------------

# action_register_package file
#
# Registers all wrapper/alternative pairs listed in the file.  This is
# supposed to be an +ALTERNATIVES file found inside a package in PKG_DBDIR.
# Each line should follow the semantics expected by action_register_wrapper.
#
action_register_package() {
    validate_args register ${#} -eq 1

    set -- $(cat ${1} | sed -e 's# #__dE/lImIt/Er__#g')
    while [ ${#} -gt 0 ]; do
        action_register_wrapper $(echo ${1} | sed -e 's#__dE/lImIt/Er__# #g')
        shift
    done
}

# -------------------------------------------------------------------------

# action_register_wrapper wrapper alternative arguments
#
# Registers a new alternative for the given wrapper in the database.
# The wrapper and its manual page are created if they do not exist.
#
action_register_wrapper() {
    validate_args register ${#} -ge 2
    validate_wrapper ${1} no
    validate_alternative ${2}

    wbase=${1}; shift
    alt=${1}; shift
    args=${*}

    filter ${wbase} || return

    wabs=${Prefix}/${wbase}
    manpage=$(get_manpage ${wbase})
    dbconf=${Db_Dir}/${wbase}
    sysconf=${Conf_Dir}/${wbase}

    if [ ! -f ${dbconf} ]; then
        info "initializing database entry for \`${wbase}'"
        mkdir_p ${dbconf%/*}
        touch ${dbconf%/*}
    fi
    info "registering alternative \`${alt}' for wrapper \`${wbase}'"
    if [ -n "${args}" ]; then
        echo "${alt} ${args}" >>${dbconf}
    else
        echo "${alt}" >>${dbconf}
    fi

    if [ ! -f ${wabs} ]; then
        info "creating wrapper \`${wbase}'"
        mkdir_p ${wabs%/*}
        sed -e "s|__ID__|@ID@|g" \
            -e "s|__SH__|@SH@|g" \
            -e "s|__CONF_FILE__|${sysconf}|g" \
            -e "s|__CREATOR__|${Prog_Name}|g" \
            -e "s|__DB_FILE__|${dbconf}|g" \
            -e "s|__ROOT_USER__|@ROOT_USER@|g" \
            -e "s|__WRAPPER__|${wabs}|g" \
            <${Data_Dir}/wrapper.sh >${wabs}
        chmod +x ${wabs}
        mkdir_p ${manpage%/*}
        sed -e "s|__CONF_FILE__|${sysconf}|g" \
            -e "s|__CREATOR__|${Prog_Name}|g" \
            -e "s|__DB_FILE__|${dbconf}|g" \
            -e "s|__PREFIX__|${Prefix}|g" \
            -e "s|__SECTION__|$(get_manpage_sect ${wbase})|g" \
            -e "s|__TITLE__|$(echo ${wbase##*/} | tr a-z A-Z)|g" \
            -e "s|__WRAPPER__|${wbase##*/}|g" \
            -e "s|__WRAPPERBASE__|${wbase}|g" \
            <${Data_Dir}/wrapper.man >${manpage}
    fi
}

# -------------------------------------------------------------------------

# action_status_package package
#
# Shows the status of each wrapper associated to the given package.
#
action_status_package() {
    validate_args status ${#} -eq 1
    validate_package ${1}
    pkg=${PKG_DBDIR}/${1}*/+ALTERNATIVES

    set -- $(cat ${pkg} | sed -e 's# #__dE/lImIt/Er__#g')
    while [ ${#} -gt 0 ]; do
        action_status_wrapper ${1%%__dE/lImIt/Er__*}
        shift
    done
}

# -------------------------------------------------------------------------

# action_status_wrapper wrapper
#
# Shows the current status for the given wrapper.
#
action_status_wrapper() {
    validate_args status ${#} -eq 1
    validate_wrapper ${1} yes

    wbase=${1}
    dbconf=${Db_Dir}/${wbase}
    sysconf=${Conf_Dir}/${wbase}
    userconf=~/.pkg_alternatives${Prefix}/${wbase}

    [ $(@ID@ -un) = @ROOT_USER@ ] && userconf=
    alts=$(cat ${userconf} ${sysconf} ${dbconf} 2>/dev/null | grep -v '^#' | \
           sed -e 's# #__dE/lImIt/Er__#g')

    found=
    for a in ${alts}; do
        prog=${a%%__dE/lImIt/Er__*}
        if [ -x ${prog} ]; then
            found=$(echo ${a} | sed -e 's#__dE/lImIt/Er__# #g')
            break
        fi
    done

    [ -n "${found}" ] ||
        err "the wrapper \`${wbase}' exists but has no valid alternatives"

    echo "\`${wbase}' points to \`${found}'"
    for a in $(echo ${alts} | tr ' ' '\n' | sort | uniq); do
        echo "    candidate: $(echo ${a} | sed -e 's#__dE/lImIt/Er__# #g')"
    done
}

# -------------------------------------------------------------------------

# action_unregister_package file
#
# Unregisters the given package (given by its +ALTERNATIVES file) and
# removes all associated alternatives from their respective wrappers.
#
action_unregister_package() {
    validate_args unregister ${#} -eq 1

    set -- $(cat ${1} | sed -e 's# #__dE/lImIt/Er__#g')
    while [ ${#} -gt 0 ]; do
        action_unregister_wrapper $(echo ${1} | sed -e 's#__dE/lImIt/Er__# #g')
        shift
    done
}

# -------------------------------------------------------------------------

# action_unregister_wrapper wrapper alternative arguments
#
# Unregisters an alternative for the given wrapper.  The lookup is done
# based on the alternative name and its arguments.  I.e., there must be
# an exact match.  If no alternatives remain after the removal, the wrapper
# and its manpage are removed.
#
action_unregister_wrapper() {
    validate_args unregister ${#} -ge 2
    validate_wrapper ${1} yes

    wbase=${1}; shift
    alt=${1}; shift
    args=${*}

    manpage=$(get_manpage ${wbase})
    dbconf=${Db_Dir}/${wbase}

    if [ -n "${args}" ]; then
        grep -v "^${alt} ${args}$" <${dbconf} >${dbconf}.new
    else
        grep -v "^${alt}$" <${dbconf} >${dbconf}.new
    fi
    if cmp -s ${dbconf} ${dbconf}.new; then
        rm -f ${dbconf}.new
        err "unknown alternative \`${alt}' for wrapper \`${wbase}'"
    fi
    mv ${dbconf}.new ${dbconf}

    if ! grep '^/' ${dbconf} >/dev/null; then
        info "no more alternatives for \`${wbase}'; removing"
        rm -f ${dbconf} ${Prefix}/${wbase} ${manpage}
        rmdir_p ${dbconf%/*}
        rmdir_p ${Prefix}/${wbase%/*}
        rmdir_p ${manpage%/*}
    fi
}

# -------------------------------------------------------------------------

# err message
#
# Prints the given error message and exist with an error code.
#
err() {
    echo "${Prog_Name}: ${*}" 1>&2
    exit 1
}

# -------------------------------------------------------------------------

# filter wrapper
#
# Reads the configuration filter from CONFDIR/filter.conf and, for the
# given wrapper, returns whether it is accepted or ignored.
#
filter() {
    [ ! -f @CONFDIR@/filter.conf ] && return 0

    if [ ${Filter_Read} = no ]; then
        Filter=$(cat @CONFDIR@/filter.conf | grep -v '^#' | sed -e 's# #__dE/lImIt/Er__#g')
        Filter_Read=yes
    fi

    [ -z "${Filter}" ] && return 0

    for f in ${Filter}; do
        what=${f%%__dE/lImIt/Er__*}
        case ${what} in
            accept)
                name=$(echo ${f#*__dE/lImIt/Er__} | sed -e 's#__dE/lImIt/Er__# #g')
                if echo ${1} | grep "${name}" >/dev/null; then
                    info "filter accepts \`${1}'"
                    return 0
                fi
                ;;
            ignore)
                name=$(echo ${f#*__dE/lImIt/Er__} | sed -e 's#__dE/lImIt/Er__# #g')
                if echo ${1} | grep "${name}" >/dev/null; then
                    info "filter ignores \`${1}'"
                    return 1
                fi
                ;;
            *)
                warn "unknown filter type \`${what}'; ignoring"
                ;;
        esac
    done

    true
}

# -------------------------------------------------------------------------

# get_my_config
#
# Prints the configuration directory for the current user.  If root, this
# is the system-wide configuration directory.  Otherwise, it is the user's
# personal directory.
#
get_my_config() {
    if [ $(@ID@ -un) = @ROOT_USER@ ]; then
        echo ${Conf_Dir}
    else
        echo ~/.pkg_alternatives${Prefix}
    fi
}

# -------------------------------------------------------------------------

# get_manpage wrapper
#
# Prints the absolute path to the manual page associated to wrapper.
# Does no error checking; validate_wrapper has to be called before this
# function to ensure wrapper is a valid name.
#
get_manpage() {
    sect=$(get_manpage_sect ${1})
    echo ${Prefix}/${PKGMANDIR}/man${sect}/${1##*/}.${sect}
}

# -------------------------------------------------------------------------

# get_manpage_sect wrapper
#
# Prints the section number that will be used by the wrapper's manpage.
# Does no error checking; validate_wrapper has to be called before this
# function to ensure wrapper is a valid name.
#
get_manpage_sect() {
    case ${1%/*} in
        bin) echo 1 ;;
        libexec|sbin) echo 8 ;;
    esac
}

# -------------------------------------------------------------------------

# info message
#
# Prints the given informative message if running in verbose mode.
#
info() {
    [ ${Verbose} = yes ] && echo "${Prog_Name}: ${*}"
}

# -------------------------------------------------------------------------

# mkdir_p directory
#
mkdir_p() {
    if [ ! -d ${1} ]; then
        cnt=2
        max=$(($(echo ${1} | tr '/' ' ' | wc -w | awk '{ print $1; }') + 1))
        while [ ${cnt} -le ${max} ]; do
            mkdir $(echo ${1} | cut -d '/' -f -${cnt}) 2>/dev/null
            cnt=$((${cnt} + 1))
        done
        [ -d ${1} ] || err "cannot create directory \`${1}'"
    fi
}

# -------------------------------------------------------------------------

# usage
#
# Shows an usage message and exits the program with an error condition.
#
usage() {
    cat 1>&2 <<EOF
Usage: ${Prog_Name} [options] action [arg1 ... argN]

Available options:
    -g        Select group mode (default).
    -p dir    Set installation prefix.
    -s        Run in silent mode.
    -w        Select wrapper mode.

Available actions in group mode:
    auto destroy list manual rebuild register status unregister

Available actions in wrapper mode:
    auto manual register status unregister

See pkg_alternatives(8) for more information.
EOF
    exit 1
}

# -------------------------------------------------------------------------

# rmdir_p directory
#
rmdir_p() {
    if [ -d ${1} ]; then
        cnt=$(($(echo ${1} | tr '/' ' ' | wc -w | awk '{ print $1; }') + 1))
        while [ ${cnt} -gt 1 ]; do
            rmdir $(echo ${1} | cut -d '/' -f -${cnt}) 2>/dev/null
            cnt=$((${cnt} - 1))
        done
    fi
}

# -------------------------------------------------------------------------

# validate_alternative name
#
# Verifies that the given program name is valid to be used as an
# alternative.
#
validate_alternative() {
    echo ${1} | grep '^/' >/dev/null || \
        err "the alternative \`${1}' is not an absolute file name"
    [ -x ${1} ] || \
        err "the alternative \`${1}' is not an executable"
}

# -------------------------------------------------------------------------

# validate_args action argcount operator expected
#
# Verifies that the number of arguments passed to the specified action
# are correct according to its semantics.  Prints an error message if
# incorrect.
#
validate_args() {
    [ ${2} ${3} ${4} ] || \
        err "incorrect number of arguments for the \`${1}' action"
}

# -------------------------------------------------------------------------

# validate_package name
#
# Verifies that the specified package is valid.
#
validate_package() {
    if [ ! -f ${PKG_DBDIR}/${1}/+ALTERNATIVES ]; then
        cnt=$(cd ${PKG_DBDIR} && ls -d ${1}-[0-9]* 2>/dev/null | wc -l | \
              awk '{ print $1; }')
        if [ "${cnt}" -eq 0 ]; then
            err "the package \`${1}' is not known"
        elif [ "${cnt}" -gt 1 ]; then
            err "multiple matches found for \`${1}'"
        fi

        # Reached this point, there is a single match for the package,
        # but it may still be wrong (i.e., no alternatives for it).
        [ ! -f ${PKG_DBDIR}/${1}*/+ALTERNATIVES ] && \
            err "no alternatives defined for the \`${1}' package"
    fi
}

# -------------------------------------------------------------------------

# validate_wrapper name exists
#
# Verifies that the specified wrapper is valid, i.e., if it belongs to a
# known directory.  Also, if the exists parameter is yes, the function
# ensures that the wrapper already exists (as well as its configuration
# file in the database).
#
validate_wrapper() {
    case ${1%/*} in
        bin|libexec|sbin)
            if [ ${2} = yes ]; then
                [ -x ${Prefix}/${1} ] || \
                    err "the wrapper \`${1}' does not exist or is not" \
                        "executable"
                [ -f ${Db_Dir}/${1} ] || \
                    err "the database configuration \`${Db_Dir}/${1}'" \
                        "does not exist"
            fi
            ;;
        *)
            err "wrapper name \`${1}' is invalid"
            ;;
    esac
}

# -------------------------------------------------------------------------

# warn message
#
# Shows a warning message.
#
warn() {
    echo "${Prog_Name}: ${*}" 1>&2
}

# -------------------------------------------------------------------------

# main
#
# Main program code.  Does argument parsing and executes the required
# action.
#
main() {
    args=$(getopt gp:sw ${*})
    [ ${?} -eq 0 ] || usage
    set -- ${args}
    what=package
    while [ ${#} -gt 0 ]; do
        case ${1} in
            -g)
                what=package
                ;;
            -p)
                Prefix=$2; shift
                Conf_Dir=@CONFDIR@${Prefix}
                Db_Dir=@DBDIR@${Prefix}
                ;;
            -s)
                Verbose=no
                ;;
            -w)
                what=wrapper
                ;;
            --)
                shift; break
                ;;
        esac
        shift
    done

    if [ ${#} -eq 0 ]; then
        usage
    fi

    action=${1}; shift
    case ${action} in
        auto|destroy|list|manual|rebuild|register|status|unregister)
            action_${action}_${what} "${@}"
            ;;
        *)
            err "unknown action \`${action}'"
            ;;
    esac

    return 0
}

main "${@}"

# vim: syntax=sh:expandtab:shiftwidth=4:softtabstop=4
