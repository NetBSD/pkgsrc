#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: sendmail.sh,v 1.3 2014/06/15 20:48:49 jnemeth Exp $
#

# PROVIDE: mail
# REQUIRE: LOGIN
#	we make mail start late, so that things like .forward's are not
#	processed until the system is fully operational


. /etc/rc.subr

name="sendmail"
rcvar=$name
pidfile="@VARBASE@/run/${name}.pid"
required_files="/etc/mail/sendmail.cf"
start_precmd="sendmail_precmd"
extra_commands="reload"

makemap="@PREFIX@/sbin/makemap"
newaliases="@PREFIX@/bin/newaliases"
smbin="@PREFIX@/libexec/sendmail/sendmail"
check_files="aliases access genericstable virtusertable domaintable mailertable"
sendmail_flags="-Lsm-mta -bd -q30m"
command=$smbin

sendmail_precmd()
{
	# check modifications on /etc/mail/ databases
	for f in ${check_files}; do
		if [ -r "/etc/mail/$f.db" ] && [ -r "/etc/mail/$f" ]; then
			if [ ! "/etc/mail/$f" -ot "/etc/mail/$f.db" ]; then
				echo \
	    "${name}: /etc/mail/$f newer than /etc/mail/$f.db, regenerating"
				if [ "x$f" = "xaliases" ]; then
					${newaliases}
				else
					${makemap} hash \
						/etc/mail/$f < /etc/mail/$f	
				fi
			fi
		fi
	done

	# check existence on /etc/mail/ databases
	for f in ${check_files}; do
		if [ ! -r "/etc/mail/$f.db" ] && [ -r "/etc/mail/$f" ]; then
			echo "${name}: /etc/mail/$f.db not present, generating"
			if [ "x$f" = "xaliases" ]; then
				${newaliases}
			else
				${makemap} hash /etc/mail/$f < /etc/mail/$f
			fi
		fi
	done
}

load_rc_config $name
run_rc_command "$1"
