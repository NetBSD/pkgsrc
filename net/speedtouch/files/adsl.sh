#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: adsl.sh,v 1.8 2005/02/04 19:32:45 tron Exp $
#
# PROVIDE: adsl
# REQUIRE: mountcritremote
# BEFORE: ipnat
#
# On systems with rc.d you will need to copy this to /etc/rc.d and set
# 'adsl=YES' in /etc/rc.conf

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="adsl"
rcvar=${name}
required_files="@PKG_SYSCONFDIR@/ppp/ppp.conf"
start_cmd="adsl_start"
stop_cmd="adsl_stop"

adsl_start()
{
	echo "Starting speedtouch adsl."
	#
	# Make sure we can see a modem and determine which revision
	# it is.
	#
	case `usbdevs -v | awk '/Speed Touch.*rev/ {print $NF}'` in
	0.00|2.00)
		firmware=kqd6_3.012 ;;
	4.00)
		firmware=zzzl_3.012 ;;
	*)
		echo "No Speed Touch modem found."
		exit 1 ;;
	esac

	# Ensure we have at least tun0 - NetBSD 1.6 and later
	ifconfig tun0 >/dev/null 2>&1 || ifconfig tun0 create
	ipcrm -S -559038737  >/dev/null 2>&1
	if ! @PREFIX@/sbin/modem_run -f @PREFIX@/libdata/speedtouch/$firmware
	then
		echo "Couldn't download firmware to modem."
		exit 1
	fi

	@PREFIX@/sbin/ppp -ddial adsl
}

adsl_stop()
{
	PPID="`ps -ax | awk '/ppp -ddial adsl *$/{print $1}'`"
	MPID="`ps -ax | awk '/modem_run -f /{print $1}'`"
	if [ -n "$PPID $MPID" ]
	then
		echo "Stopping speedtouch adsl."
		kill $PPID $MPID >/dev/null 2>&1
		sleep 1
		ipcrm -S -559038737 >/dev/null 2>&1
	fi
}

if [ -f /etc/rc.subr ]
then
        load_rc_config $name
        run_rc_command "$1"
else
        echo -n ' ${name}'
        exec ${command} ${smbd_flags} ${command_args}
fi
