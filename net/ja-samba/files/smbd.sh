#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: smbd.sh,v 1.2 2002/09/20 02:01:58 grant Exp $
#
# PROVIDE: smbd
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="smbd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
required_files="@SAMBA_ETCDIR@/smb.conf"
extra_commands="reload"
command_args="-D"		# _must_ start as daemon from rc.d;
				# add more flags through ${${name}_flags}

if [ -f /etc/rc.subr ]
then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n ' ${name}'
	${command} ${smbd_flags} ${command_args}
fi
