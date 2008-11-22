#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: hal.sh,v 1.2 2008/11/22 16:16:26 jmcneill Exp $
#
# PROVIDE: hal
# REQUIRE: DAEMON dbus
# KEYWORD: shutdown

. /etc/rc.subr

name="hal"
rcvar=$name
command="@PREFIX@/sbin/hald"
start_precmd=hal_prestart

hal_prestart() {
	dir="@VARBASE@/run/hald"
	if @TEST@ ! -d $dir; then
		@MKDIR@ $dir
		@CHMOD@ 0755 $dir
		@CHOWN@ @HAL_USER@:@HAL_GROUP@ $dir
	fi
	@CHMOD@ 0755 "@VARBASE@/cache"
}

load_rc_config $name
run_rc_command "$1"
