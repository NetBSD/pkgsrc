#!@RCD_SCRIPTS_SHELL@

# PROVIDE: authelia
# REQUIRE: DAEMON
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="authelia"
rcvar=$name
authelia_user="@AUTHELIA_USER@"
authelia_group="@AUTHELIA_GROUP@"
command="@PREFIX@/bin/authelia"
command_args="--config @PKG_SYSCONFDIR@/authelia.yml < /dev/null > /dev/null 2>&1 &"

if [ -f /etc/rc.subr -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	if [ -f /etc/rc.conf ]; then
		. /etc/rc.conf
	fi
	echo "$0: No support for non-rc.subr pkgsrc installations. Patches welcome."
	exit 1
fi
