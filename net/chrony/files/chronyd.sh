#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: chronyd.sh,v 1.4.84.1 2013/08/21 12:59:44 tron Exp $
#
# PROVIDE: chronyd
# REQUIRE: DAEMON

. /etc/rc.subr

name="chronyd"
command="@PREFIX@/sbin/${name}"
pidfile="@VARBASE@/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/chrony.conf"
extra_commands="online offline"
online_cmd="chronyd_online"
online_precmd="chronyd_precmd"
offline_cmd="chronyd_offline"
offline_precmd="chronyd_precmd"

chronyd_precmd()
{
	local id kfile
	id=`awk '$1 == "commandkey" { print $2 }' @PKG_SYSCONFDIR@/chrony.conf`
	if [ -z "$id" ]; then
		echo "ERROR: no commandkey in @PKG_SYSCONFDIR@/chrony.conf!"
		exit 1
	fi
	kfile=`awk '$1 == "keyfile" { print $2 }' @PKG_SYSCONFDIR@/chrony.conf`
	if [ -z "$kfile" ]; then
		echo "ERROR: no keyfile in @PKG_SYSCONFDIR@/chrony.conf!"
		exit 1
	fi
	chronyd_password=`awk '$1 == "'$id'" { print $2 }' $kfile`
	if [ -z "$chronyd_password" ]; then
		echo "ERROR: no key #$id in $kfile!"
		exit 1
	fi
}

chronyd_online()
{
	printf "password %s\nonline\n" $chronyd_password | @PREFIX@/bin/chronyc
}

chronyd_offline()
{
	printf "password %s\noffline\n" $chronyd_password | @PREFIX@/bin/chronyc
}

load_rc_config $name
run_rc_command "$1"
