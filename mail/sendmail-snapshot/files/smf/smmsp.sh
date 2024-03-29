#!/sbin/sh
#
# $NetBSD: smmsp.sh,v 1.1 2024/01/15 04:50:55 jnemeth Exp $
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
# Copyright 2009 Sun Microsystems, Inc.  All rights reserved.
# Use is subject to license terms.

. /lib/svc/share/smf_include.sh
. @PREFIX@/lib/svc/method/sendmail_include

CLIENT_PID_FILE="@VARBASE@/spool/clientmqueue/sm-client.pid"
SUBMIT_CF="/etc/mail/submit.cf"

case "$1" in 
'refresh')
        [ -f $CLIENT_PID_FILE ] && kill -1 `head -1 $CLIENT_PID_FILE`
        ;;

'start')
	exist_or_exit $SENDMAIL
	[ -f $DEFAULT_FILE ] && . $DEFAULT_FILE
	#
	# * CLIENTQUEUEINTERVAL should be set to some legal value;
	#   sanity checks are done below.
	# * CLIENTOPTIONS are catch-alls; set with care.
	#
	check_queue_interval_syntax $CLIENTQUEUEINTERVAL
	CLIENTQUEUEINTERVAL=$answer

	submit_path=`svcprop -p config/path_to_submit_mc $SMF_FMRI 2>/dev/null`
	if [ $? -eq 0 -a -n "$submit_path" ]; then
		turn_m4_crank "$SUBMIT_CF" "$submit_path"
	fi
	exist_or_exit "$SUBMIT_CF"

	$SENDMAIL -Ac -q$CLIENTQUEUEINTERVAL $CLIENTOPTIONS &
	;;

'stop')
	if [ -f $CLIENT_PID_FILE ]; then
		check_and_kill $CLIENT_PID_FILE
		rm -f $CLIENT_PID_FILE
	fi
	# Need to kill the entire service contract to kill all sendmail related
	# processes
	smf_kill_contract $2 TERM 1 30
	ret=$?
	[ $ret -eq 1 ] && exit 1

	# Sendmail can take its time responding to SIGTERM, as it waits for
	# things like child processes and SMTP connections to clean up.  If
	# the contract did not empty after TERM, move on to KILL.
	if [ $ret -eq 2 ] ; then
		smf_kill_contract $2 KILL 1
	fi
	;;

*)
	echo "Usage: $0 { start | stop | refresh }"
	exit 1
	;;
esac
exit 0
