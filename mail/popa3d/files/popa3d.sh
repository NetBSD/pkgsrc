#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: popa3d.sh,v 1.1 2002/11/07 03:50:08 dillo Exp $
#
# PROVIDE: popa3d
# REQUIRE: DAEMON LOGIN

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="popa3d"
rcvar=$name
command="@PREFIX@/sbin/${name}"
command_args="-D"		# _must_ start as daemon from rc.d;
				# add more flags through ${${name}_flags}

if [ -f /etc/rc.subr -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]; then
	load_rc_config $name
	eval [ -z "\$${rcvar}" ] && eval ${rcvar}=NO
	run_rc_command "$1"
else
	echo -n ' ${name}'
	${command} ${popa3d_flags} ${command_args}
fi
