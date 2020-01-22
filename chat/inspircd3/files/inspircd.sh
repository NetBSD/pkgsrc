#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: inspircd.sh,v 1.2 2020/01/22 10:27:58 nia Exp $
#
# PROVIDE: inspircd
# REQUIRE: DAEMON

. /etc/rc.subr

name="inspircd"
rcvar=${name}
command="@PREFIX@/bin/inspircd"
required_files="@PKG_SYSCONFDIR@/inspircd.conf"
pidfile="@PREFIX@/inspircd/${name}.pid"
extra_commands="rehash sslrehash"
rehash_cmd="inspircd_rehash"
sslrehash_cmd="inspircd_sslrehash"

inspircd_user="@INSPIRCD_USER@"
inspircd_group="@INSPIRCD_GROUP@"

inspircd_rehash() {
	kill -1 $(@CAT@ ${pidfile})
}

inspircd_sslrehash() {
	kill -USR1 $(@CAT@ ${pidfile})
}

load_rc_config $name
run_rc_command "$1"
