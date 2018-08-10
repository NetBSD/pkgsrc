#!@RCD_SCRIPTS_SHELL@

# PROVIDE: geomyidae
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="geomyidae"
rcvar=$name
command="@PREFIX@/sbin/geomyidae"

geomyidae_flags=${geomyidae_flags-"-u @GEOMYIDAE_USER@ -g @GEOMYIDAE_GROUP@ -b @GEOMYIDAE_ROOTDIR@"}

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	echo -n "${name}"
	${command} ${geomyidae_flags} ${command_args} 
fi
