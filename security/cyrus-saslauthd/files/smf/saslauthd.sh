#!@SMF_METHOD_SHELL@
#
# $NetBSD: saslauthd.sh,v 1.1 2016/12/16 15:42:20 hans Exp $
#
# This file and its contents are supplied under the terms of the
# Common Development and Distribution License ("CDDL"), version 1.0.
# You may only use this file in accordance with the terms of version
# 1.0 of the CDDL.
#
# A full copy of the text of the CDDL should have accompanied this
# source.  A copy of the CDDL is also available via the Internet at
# http://www.illumos.org/license/CDDL.
#
# Copyright 2016 Hans Rosenfeld <rosenfeld@grumpf.hope-2000.org>
#

# smf_method(5) start/stop script required for cyrus-saslauthd

. /lib/svc/share/smf_include.sh


get_config ()
{   
    cmdopts=""
    properties="authmech mechopts nthreads caching sockpath"

    for prop in $properties
    do
        value=`/usr/bin/svcprop -p options/${prop} ${SMF_FMRI}`
        if [ -z "${value}" -o "${value}" = '""' ]; then
            continue;
        fi

        case $prop in
        'caching')
            if [ ${value} = "true" ]; then
                cmdopts="${cmdopts} -c"
            fi
            ;;
        'authmech')
            authmech=${value}
            ;;
        'mechopts')
            cmdopts="${cmdopts} -O ${value}"
            ;;
        'nthreads')
            if [ ${value} -gt 0 ]; then
                cmdopts="${cmdopts} -n ${value}"
            fi
            ;;
        'sockpath')
            cmdopts="${cmdopts} -m ${value}"
            sockpath=${value}
            ;;
        esac
    done
}

result=${SMF_EXIT_OK}

# Set defaults; SMF_FMRI should have been set, but just in case.
if [ -z "$SMF_FMRI" ]; then
    SMF_FMRI="svc:/@SMF_PREFIX@/@SMF_NAME@:${instance}"
fi

get_config

if [ -z "${authmech}" ]; then
    echo "saslauthd: authmech must be set"
    exit ${SMF_EXIT_ERR_CONFIG}
fi

if [ ! -z "${sockpath}" -a ! -d "${sockpath}" ]; then
    mkdir -p ${sockpath}
    chmod 0755 ${sockpath}
    chown root ${sockpath}
fi

# Execute spamd with relevant command line options.
ppriv -s A-all -s A+basic,net_privaddr,file_dac_read,file_dac_search,sys_resource,proc_setid -e @PREFIX@/sbin/saslauthd -a ${authmech} ${cmdopts}

exit $?
