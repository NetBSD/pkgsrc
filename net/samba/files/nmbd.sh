#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: nmbd.sh,v 1.8 2002/09/20 02:01:58 grant Exp $
#
# PROVIDE: nmbd
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="nmbd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
required_files="@SAMBA_ETCDIR@/smb.conf"
extra_commands="reload"
command_args="-D"		# _must_ start as daemon from rc.d;
				# add more flags through ${${name}_flags}

reload_cmd=":"			# avoid dumping debug output on SIGHUP

if [ -f /etc/rc.subr ]
then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n ' ${name}'
	${command} ${nmbd_flags} ${command_args}
fi
