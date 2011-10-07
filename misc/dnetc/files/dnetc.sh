#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dnetc.sh,v 1.2 2011/10/07 22:37:03 shattered Exp $
#

# PROVIDE: dnetc
# REQUIRE: LOGIN
# KEYWORD: shutdown

. /etc/rc.subr

dnetc_user="nobody"
dnetc_group="nobody"
dnetc_homedir="/var/db/dnetc"

name="dnetc"
rcvar=$name
extra_commands="config"
# XXX: We cannot use the full pathname to call dnetc's binary directly.
# Doing so means it will not work properly.
PATH=@PREFIX@/bin:/bin:/sbin:/usr/bin:/usr/sbin
command="${name}"

dnetc_config() {
	if [ ! -d ${dnetc_homedir} ]; then
		mkdir ${dnetc_homedir}
		chmod 755 ${dnetc_homedir}
		chown ${dnetc_user}:${dnetc_group} ${dnetc_homedir}
	fi

	su -fm ${dnetc_user} -c "cd ${dnetc_homedir} && exec ${command} -config"
	return 0
}

dnetc_start() {
	if [ ! -f ${dnetc_homedir}/dnetc.ini ]; then
		run_rc_command config
	fi

	echo "Starting ${name}."
	su -fm ${dnetc_user} -c "cd ${dnetc_homedir} && exec ${command} &" \
	    2>/dev/null 1>/dev/null
}

config_cmd=dnetc_config
start_cmd=dnetc_start

load_rc_config $name
run_rc_command "$1"
