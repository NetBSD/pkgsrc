#!/bin/sh
#
# $NetBSD: setiathome.sh,v 1.2 2003/05/01 18:07:55 jmmv Exp $
#

# PROVIDE: setiathome
# REQUIRE: LOGIN
# KEYWORD: shutdown

. /etc/rc.subr

sah_user="nobody"
sah_group="nobody"
sah_homedir="/var/db/setiathome"

name="setiathome"
rcvar=$name
command="@PREFIX@/bin/${name}"
pidfile="${sah_homedir}/pid.sah"
extra_commands="config"

setiathome_config() {
	if [ ! -d ${sah_homedir} ]; then
		mkdir ${sah_homedir}
		chmod 755 ${sah_homedir}
		chown ${sah_user}:${sah_group} ${sah_homedir}
	fi

	su -fm ${sah_user} -c "cd ${sah_homedir} && exec ${command} -login"
	return 0
}

setiathome_start() {
	if [ ! -f ${sah_homedir}/key.sah ]; then
		run_rc_command config
	fi

	echo "Starting ${name}."
	su -fm ${sah_user} -c "cd ${sah_homedir} && exec ${command} \
		${command_args} &" 2>/dev/null 1>/dev/null
}

setiathome_poststop() {
	rm -f ${sah_homedir}/pid.sah
}

config_cmd=setiathome_config
start_cmd=setiathome_start
stop_postcmd=setiathome_poststop

load_rc_config $name
run_rc_command "$1"
