#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: oss.sh,v 1.3 2002/10/02 21:06:55 jlam Exp $
#
# PROVIDE: oss
# REQUIRE: aftermountlkm
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="oss"
rcvar=$name
required_files="/etc/oss.conf @OSSLIBDIR@/devices.cfg"
start_cmd="oss_start"
stop_cmd="oss_stop"

oss_start()
{
	missing_files=
	for file in ${required_files}; do
		if [ ! -f "${file}" ]; then
			missing_files="${missing_files} ${file}"
		fi
	done
	if [ -z "${missing_files}" -a -x @PREFIX@/sbin/soundon ]; then
		@ECHO@ "Starting ${name}."
		@PREFIX@/sbin/soundon
	fi
}

oss_stop()
{
        if modstat -n oss >/dev/null; then
		if [ -x @PREFIX@/sbin/soundoff ]; then
			@ECHO@ "Stopping ${name}."
			@PREFIX@/sbin/soundoff
		fi
	fi
}


if [ -f /etc/rc.subr -a -f /etc/rc.conf -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]
then
	load_rc_config $name
	run_rc_command "$1"
else
	$start_cmd
fi
