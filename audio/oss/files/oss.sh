#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: oss.sh,v 1.2 2002/10/02 20:46:46 jlam Exp $
#
# PROVIDE: oss
# REQUIRE: aftermountlkm
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="oss"
rcvar=$name
required_files="/etc/oss.conf"
start_cmd="oss_start"
stop_cmd="oss_stop"

oss_start()
{
	if [ -x @PREFIX@/bin/soundon ]; then
		@ECHO@ "Starting ${name}."
		@PREFIX@/bin/soundon
	fi
}

oss_stop()
{
	if [ -x @PREFIX@/bin/soundoff ]; then
		@ECHO@ "Stopping ${name}."
		@PREFIX@/bin/soundoff
	fi
}


if [ -f /etc/rc.subr -a -f /etc/rc.conf -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]
then
	load_rc_config $name
	run_rc_command "$1"
else
	$start_cmd
fi
