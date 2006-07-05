#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: sj3.sh,v 1.2 2006/07/05 04:55:24 jlam Exp $
#
# PROVIDE: sj3
# REQUIRE: LOGIN
#

. /etc/rc.subr

name="sj3"
rcvar=$name
command="@PREFIX@/bin/sj3serv"
start_precmd="sj3_prestart"

mkdir_perms() {
	dir="$1"; user="$2"; group="$3"; mode="$4"
	@TEST@ -d $dir || @MKDIR@ $dir
	@CHOWN@ $user $dir
	@CHGRP@ $group $dir
	@CHMOD@ $mode $dir
}

sj3_prestart()
{
	@MKDIR@ @IMDICTDIR@/sj3
	mkdir_perms @IMDICTDIR@/sj3/user @SJ3OWNER@ @SJ3GROUP@ 0755
	srcdict="@PREFIX@/libdata/sj3main.dic"
	dict="@IMDICTDIR@/sj3/sj3main.dic"
	if @TEST@ -f $srcdict; then
		@RM@ -f $srcdict
		@LN@ -fs $srcdict $dict
	fi
}

load_rc_config $name
run_rc_command "$1"
