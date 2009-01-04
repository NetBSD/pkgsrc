#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: inspircd.sh,v 1.1.1.1 2009/01/04 00:52:27 adrianp Exp $
#
# PROVIDE: inspircd
# REQUIRE: DAEMON
# KEYWORD: shutdown
#

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="inspircd"
rcvar=${name}
command="@PREFIX@/bin/inspircd"
required_files="@PKG_SYSCONFDIR@/inspircd.conf"
pidfile="@VARBASE@/run/inspircd/inspircd.pid"
inspircd_user="@INSPIRCD_USER@"
inspircd_group="@INSPIRCD_GROUP@"
command_args="--logfile @VARBASE@/log/inspircd.log"
extra_commands="rehash"
rehash_cmd="inspircd_rehash"
start_precmd="inspircd_precmd"

inspircd_precmd()
{
	if [ ! -d @VARBASE@/run/inspircd ]; then
		@MKDIR@ @VARBASE@/run/inspircd
		@CHMOD@ 0750 @VARBASE@/run/inspircd
		@CHOWN@ @INSPIRCD_USER@:@INSPIRCD_GROUP@ @VARBASE@/run/inspircd
	fi

	if [ ! -f @VARBASE@/log/inspircd.log ]; then
		@TOUCH@ @VARBASE@/log/inspircd.log
		@CHMOD@ 0640 @VARBASE@/log/inspircd.log
		@CHOWN@ @INSPIRCD_USER@:@INSPIRCD_GROUP@ @VARBASE@/log/inspircd.log
	fi
}

inspircd_rehash()
{
	kill -HUP `@CAT@ $pidfile`
}

load_rc_config $name
run_rc_command "$1"
