#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: spectrum.sh,v 1.1.1.1 2011/02/07 06:31:22 schnoebe Exp $
#
#   startup script for the spectrum jabber transport service
#
# PROVIDE: spectrum
# REQUIRE: DAEMON s2s
#
if [ -f /etc/rc.subr ]; then
    . /etc/rc.subr
fi

name="spectrum"
rcvar="$name"
procname="$name"
command=@PREFIX@/bin/spectrumctl

start_cmd="$command start"
restart_cmd="$command restart"
stop_cmd="$command stop"

ensure_piddir()
{
	mkdir -p @JABBER_PIDDIR@ @JABBER_LOGDIR@
	chown @JABBER_USER@ @JABBER_PIDDIR@ @JABBER_LOGDIR@
}

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} $1
fi
