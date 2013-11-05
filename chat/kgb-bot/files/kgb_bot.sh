#!/bin/sh
#
# $NetBSD: kgb_bot.sh,v 1.1 2013/11/05 02:13:42 tonnerre Exp $
#
# PROVIDE: kgb_bot
# REQUIRE: DAEMON

. /etc/rc.subr

name="kgb_bot"
rcvar=$name
command="@PREFIX@/sbin/kgb-bot"
required_files="@PKG_SYSCONFDIR@/kgb-bot/kgb.conf"

load_rc_config $name
run_rc_command "$1"
