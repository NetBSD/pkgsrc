#!@SMF_METHOD_SHELL@
#
# $NetBSD: spamassassin.sh,v 1.1 2016/12/16 15:52:52 hans Exp $
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

# smf_method(5) start/stop script required for spamassassin spamd

. /lib/svc/share/smf_include.sh


get_config ()
{   
    cmdopts=""
    properties="allow-tell listen-on allowed-ips max-children user local-only
	log-facility"

    for prop in $properties
    do
        value=`/usr/bin/svcprop -p options/${prop} ${SMF_FMRI}`
        if [ -z "${value}" -o "${value}" = '""' ]; then
            continue;
        fi

        case $prop in
        'allow-tell')
            if [ ${value} = "true" ]; then
                cmdopts="${cmdopts} --allow-tell"
            fi
            ;;
        'listen-on')
            cmdopts="${cmdopts} --listen=${value}"
            ;;
        'allowed-ips')
            cmdopts="${cmdopts} --allowed-ips=${value}"
            ;;
        'max-children')
            if [ ${value} -gt 0 ]; then
                cmdopts="${cmdopts} --max-children=${value}"
            fi
            ;;
        'user')
            cmdopts="${cmdopts} --user=${value}"
            ;;
        'local-only')
            if [ ${value} = "true" ]; then
                cmdopts="${cmdopts} --local"
            fi
            ;;
        'log-facility')
            cmdopts="${cmdopts} --syslog=${value}"
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
ppriv -s A-all -s A+basic,net_privaddr,file_dac_read,file_dac_search,sys_resource,proc_setid -e @PREFIX@/bin/spamd -d --syslog-socket=native ${cmdopts}

exit $?
