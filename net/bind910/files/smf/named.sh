#!@SMF_METHOD_SHELL@
#
# CDDL HEADER START
#
# The contents of this file are subject to the terms of the
# Common Development and Distribution License (the "License").
# You may not use this file except in compliance with the License.
#
# You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE
# or http://www.opensolaris.org/os/licensing.
# See the License for the specific language governing permissions
# and limitations under the License.
#
# When distributing Covered Code, include this CDDL HEADER in each
# file and include the License file at usr/src/OPENSOLARIS.LICENSE.
# If applicable, add the following below this CDDL HEADER, with the
# fields enclosed by brackets "[]" replaced with your own identifying
# information: Portions Copyright [yyyy] [name of copyright owner]
#
# CDDL HEADER END
#
# Copyright 2007 Sun Microsystems, Inc.  All rights reserved.
# Use is subject to license terms.
#
#pragma ident	"@(#)dns-server.sh	1.1	07/03/26 SMI"

# smf_method(5) start/stop script required for server DNS

. /lib/svc/share/smf_include.sh

result=${SMF_EXIT_OK}

# Read command line arguments
method="$1"		# %m
instance="$2" 		# %i

# Set defaults; SMF_FMRI should have been set, but just in case.
if [ -z "$SMF_FMRI" ]; then
    SMF_FMRI="svc:/@SMF_PREFIX@/@SMF_NAME@:${instance}"
fi
server="@PREFIX@/sbin/named"
I=`/usr/bin/basename $0`

case "$method" in
'start')
    cmdopts=""
    properties="debug_level ip_interfaces listen_on_port
	threads chroot_dir configuration_file server"

    for prop in $properties
    do
	value=`/usr/bin/svcprop -p options/${prop} ${SMF_FMRI}`
	if [ -z "${value}" -o "${value}" = '""' ]; then
	    continue;
	fi

	case $prop in
	'debug_level')
	    if [ ${value} -gt 0 ]; then
		cmdopts="${cmdopts} -d ${value}"
	    fi
	    ;;
	'ip_interfaces')
	    case ${value} in
		'IPv4')
		    cmdopts="${cmdopts} -4";;
		'IPv6')
		    cmdopts="${cmdopts} -6";;
		'all')
		    :	# Default is all, therefore ignore.
		    ;;
		*)
		    echo "$I: Unrecognised value in service instance property" >&2
		    echo "$I: options/${prop} : ${value}" >&2
		    ;;
	    esac
	    ;;
	'listen_on_port')
	    if [ ${value} -gt 0 ]; then
		cmdopts="${cmdopts} -p ${value}"
	    fi
	    ;;
	'threads')
	    if [ ${value} -gt 0 ]; then
		cmdopts="${cmdopts} -n ${value}"
	    fi
	    ;;
	'chroot_dir')
	    cmdopts="${cmdopts} -t ${value}"
	    ;;
	'configuration_file')
	    cmdopts="${cmdopts} -c ${value}"
	    ;;
	'server')
	    set -- `echo ${value} | /usr/bin/sed -e  's/\\\\//g'`
	    server=$@
	    ;;
	esac
    done

    if [ ${result} = ${SMF_EXIT_OK} ]; then
	echo "$I: Executing: ${server} ${cmdopts}"
	# Execute named(1M) with relevant command line options.
	${server} ${cmdopts}
	result=$?
    fi
    ;;
'stop')
	smf_kill_contract ${contract} TERM 1
	[ $? -ne 0 ] && exit 1
	;;
*)
	echo "Usage: $I [stop|start] <instance>" >&2
	exit 1
	;;
esac
exit ${result}
