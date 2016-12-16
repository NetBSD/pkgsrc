#!@SMF_METHOD_SHELL@
#
# $NetBSD: spamass-milter.sh,v 1.1 2016/12/16 15:56:05 hans Exp $
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

# smf_method(5) start/stop script required for spamass-milter

. /lib/svc/share/smf_include.sh


get_config ()
{   
    cmdopts=""
    # spamc-flags must be last
    properties="socket-path reject-code reject-text reject-threshold ignore-nets ignore-auth default-user lookup-users spamc-flags"

    for prop in $properties
    do
        value=`/usr/bin/svcprop -p options/${prop} ${SMF_FMRI}`
        if [ -z "${value}" -o "${value}" = '""' ]; then
            continue;
        fi

        case $prop in
        'socket-path')
            cmdopts="${cmdopts} -p ${value}"
            ;;
        'reject-code')
            cmdopts="${cmdopts} -C ${value}"
            ;;
        'reject-text')
            cmdopts="${cmdopts} -R ${value}"
            ;;
        'reject-threshold')
            if [ ${value} != "0" ]; then
                cmdopts="${cmdopts} -r ${value}"
            fi
            ;;
        'ignore-nets')
            cmdopts="${cmdopts} -i ${value}"
            ;;
        'ignore-auth')
            if [ ${value} = "true" ]; then
                cmdopts="${cmdopts} -a"
            fi
            ;;
        'default-user')
            cmdopts="${cmdopts} -u ${value}"
            ;;
        'lookup-users')
            if [ ${value} = "true" ]; then
                cmdopts="${cmdopts} -x"
            fi
            ;;
        'spamc-flags')
            value=`echo ${value} | sed -e 's/\\\\//g'`
            cmdopts="${cmdopts} -- ${value}"
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

# Execute spamd with relevant command line options.
ppriv -s A-all -s A+basic,net_privaddr,file_dac_read,file_dac_search,sys_resource,proc_setid -e @PREFIX@/sbin/spamass-milter -f ${cmdopts}

exit $?
