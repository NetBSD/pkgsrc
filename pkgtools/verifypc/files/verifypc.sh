#!@SH@
#
# $NetBSD: verifypc.sh,v 1.5 2006/09/14 15:35:46 jmmv Exp $
#
# verifypc - Sanity check package dependencies according to pkg-config
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
#    without specific prior written permission.
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

: ${MAKE:=@MAKE@}

: ${VERIFYPC_IGNORE:=}

SORTED_DEPS=

# -------------------------------------------------------------------------

#
# Show an error message on stderr and exit.
#
err() {
    echo "verifypc: ${@}" 1>&2
    exit 1
}

# -------------------------------------------------------------------------

#
# Show a warning message on stderr.
#
warn() {
    echo "verifypc: ${@}" 1>&2
}

# -------------------------------------------------------------------------

#
# Checks if the file passed as an argument belongs to any of our direct
# dependencies.
#
search_file_in_depends() {
    local file="${1}"
    local dep dir file

    for dep in ${SORTED_DEPS}; do
        dir=$(echo ${dep} | cut -d : -f 2)
        if [ -d ${dir} ] && grep ${file} ${dir}/PLIST* >/dev/null; then
            echo ${dep}
            return
        fi
    done
}

# -------------------------------------------------------------------------

#
# Checks if the pkg-config dependency specification is satisfied by
# the 'dep' package dependency.
#
check_match() {
    local dep="${1}" pcname="${2}" pcop="${3}" pcver="${4}"
    local out pkgdep pkgname ret

    if [ ${pcop} != ">" -a ${pcop} != ">=" -a ${pcop} != "-" ]; then
        warn "unsupported operator ${pcop} in ${pcname} dependency"
        return 1
    fi

    pkgdep=$(echo ${dep} | cut -d : -f 1 | sed 's|>=|-|;s|>|-|')
    pkgname=$(echo ${pkgdep} | sed 's|^\(.*\)-\([0-9].*\)$|\1|')

    out=$(pkg_admin pmatch "${pkgname}${pcop}${pcver}" "${pkgdep}" 2>&1)
    ret=$?
    if [ ${ret} -ne 0 ]; then
        warn "${pcname} not correct; '${pcop} ${pcver}' needed"
        return 1
    elif [ -n "${out}" ]; then
        warn "${pcname} pmatch failed; wanted" \
            "${pkgname}${pcop}${pcver}, have ${pkgdep}"
        return 1
    fi
    return 0
}

# -------------------------------------------------------------------------

#
# Main program.
#
main() {
    local dep error lines log pcname pcop pcver

    [ -f Makefile -a -f ../../mk/bsd.pkg.mk ] ||
        err "must be run within a package directory"

    log=$(${MAKE} show-var VARNAME=_PKG_CONFIG_LOG)

    [ -f ${log} ] ||
        err "pkg-config log not found; must run '${MAKE} configure' first"

    # Construct a list of dependency specifications for the current package.
    SORTED_DEPS=$(${MAKE} show-vars VARNAMES="BUILD_DEPENDS DEPENDS" | tr ' ' '
' | sed 's,\([.<>=]\)\([0-9][.:n]\),\10\2,g' | \
    sed 's,\([.<>=]\)\([0-9][.:n]\),\10\2,g' | \
    sort -r | \
    sed 's,\([.<>=]\)0\([0-9][.:n]\),\1\2,g' | \
    sed 's,\([.<>=]\)0\([0-9][.:n]\),\1\2,g' | \
    uniq)

    error=0
    lines=$(cat ${log} | sort | uniq | tr ' ' '¬')
    for l in ${lines}; do
        pcname=$(echo ${l} | cut -d '¬' -f 1)
        pcop=$(echo ${l} | cut -d '¬' -f 2)
        pcver=$(echo ${l} | cut -d '¬' -f 3)

        dep=$(search_file_in_depends pkgconfig/${pcname}.pc)
        if [ -n "${dep}" -a "${pcop}" != "NOT-FOUND" ]; then
            # The package passed to pkg-config is correct, as we have it
            # among our dependencies.  If we are requiring an specific
            # version of it, let's check if it is correct.
            if [ ${pcop} != "(any)" ]; then
                check_match ${dep} ${pcname} ${pcop} ${pcver}
                [ $? -eq 0 ] || error=1
            fi
        else
            # The package passed to pkg-config cannot be found among our
            # dependencies or it does not exist; tell the user.
            if echo ${VERIFYPC_IGNORE} | \
                egrep "^${pcname}$|^${pcname} | ${pcname} | ${pcname}$" \
                >/dev/null
            then
                : # Package explicitly ignored by the user, so shut up.
            else
                if [ "${pcop}" != "NOT-FOUND" ]; then
                    warn "${pcname} not a direct dependency"
                else
                    warn "${pcname} not found"
                fi
                error=1
            fi
        fi
    done

    return ${error}
}

main "${@}"
