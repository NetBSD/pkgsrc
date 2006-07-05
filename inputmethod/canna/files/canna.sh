#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: canna.sh,v 1.2 2006/07/05 04:48:28 jlam Exp $
#
# PROVIDE: canna
# REQUIRE: DAEMON

. /etc/rc.subr

name="canna"
rcvar=$name
command="@PREFIX@/sbin/cannaserver"
start_precmd="canna_prestart"
stop_cmd="@PREFIX@/sbin/cannakill"

mkdir_perms() {
	dir="$1"; user="$2"; group="$3"; mode="$4"
	@TEST@ -d $dir || @MKDIR@ $dir
	@CHOWN@ $user $dir
	@CHGRP@ $group $dir
	@CHMOD@ $mode $dir
}

canna_prestart()
{
	mkdir_perms @CANNA_SPOOL@ @CANNA_USER@ @CANNA_GROUP@ 0755
	mkdir_perms @IMDICTDIR@/canna @CANNA_USER@ @CANNA_GROUP@ 0775
	mkdir_perms @IMDICTDIR@/canna/canna @CANNA_USER@ @CANNA_GROUP@ 0775

	srcdictdir="@PREFIX@/libdata/canna"
	dictdir="@IMDICTDIR@/canna/canna"
	if @TEST@ -d $srcdictdir; then
		( cd $srcdictdir; for f in *; do
			@TEST@ "$f" != "*" || continue
			@RM@ -f $dictdir/$f
			@LN@ -fs $srcdictdir/$f $dictdir/$f
		done )
	fi
}

load_rc_config $name
run_rc_command "$1"
