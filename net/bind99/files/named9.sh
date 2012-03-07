#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: named9.sh,v 1.1.1.1 2012/03/07 14:25:00 taca Exp $
#

# PROVIDE: named
# REQUIRE: NETWORKING mountcritremote syslogd
# BEFORE:  DAEMON
# KEYWORD: chrootdir

. /etc/rc.subr

name="named"
rcvar="${name}9"
command="@PREFIX@/sbin/${name}"
pidfile="@VARBASE@/run/named/${name}.pid"
start_precmd="named_precmd"
extra_commands="reload"
required_dirs="$named_chrootdir"	# if it is set, it must exist

named_precmd()
{
	# Die if $named is also set (i.e. the system's named is not disabled
	if checkyesno named ; then
		warn \
	"disable 'named' when setting 'named9'!"
		return 1
	fi

       	if [ ! -d @VARBASE@/run/named ]; then 
		@MKDIR@ @VARBASE@/run/named 
       	fi      

	if [ -z "$named_chrootdir" ]; then
		return 0;
	fi

	for i in null random
	do
		if [ ! -c "${named_chrootdir}/dev/$i" ]; then
			@RM@ -f "${named_chrootdir}/dev/$i"
			(cd /dev &&
				@PAX@ -rw -pe "$i" "${named_chrootdir}/dev")
		fi
	done

	if [ -f /etc/localtime ]; then
		@CMP@ -s /etc/localtime "${named_chrootdir}/etc/localtime" || \
		    @CP@ -p /etc/localtime "${named_chrootdir}/etc/localtime"
	fi

       	if [ ! -d ${named_chrootdir}@VARBASE@/run/named ]; then 
		@MKDIR@ ${named_chrootdir}@VARBASE@/run/named 
		@CHOWN@ @BIND_USER@ ${named_chrootdir}@VARBASE@/run/named
       	fi      

	@RM@ -f ${pidfile}
	@LN@ -s "${named_chrootdir}${pidfile}" ${pidfile}

	#	Change run_rc_commands()'s internal copy of $named_flags
	#
	rc_flags="-u @BIND_USER@ -t ${named_chrootdir} $rc_flags"
}

load_rc_config "$rcvar"
run_rc_command "$1"
