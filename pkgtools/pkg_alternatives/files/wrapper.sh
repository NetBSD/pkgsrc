#!__SH__
#
# $NetBSD: wrapper.sh,v 1.2 2012/06/13 15:35:32 jperkin Exp $
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

wrapper="__WRAPPER__"
progname="${wrapper##*/} (wrapper)"

if [ ! -f __DB_FILE__ ]; then
    echo "${progname}: cannot open __DB_FILE__" 1>&2
    exit 1
fi

if [ $(__ID__ -un) = __ROOT_USER__ ]; then
    userfile=
else
    userfile=~/.pkg_alternatives/${wrapper}
fi
alternatives=$(cat ${userfile} __CONF_FILE__ __DB_FILE__ 2>/dev/null | \
               grep -v "^#" | sed -e 's# #__dE/lImIt/Er__#g')

found=
for a in ${alternatives}; do
    prog=${a%%__dE/lImIt/Er__*}
    if [ -x ${prog} ]; then
        found=$(echo ${a} | sed -e 's#__dE/lImIt/Er__# #g')
	break
    fi
done

if [ -z "${found}" ]; then
    echo "${progname}: no alternatives found" 1>&2
    exit 1
fi

exec ${found} "${@}"
