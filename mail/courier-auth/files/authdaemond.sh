#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: authdaemond.sh,v 1.8 2004/07/14 20:07:07 jlam Exp $
#
# Courier user authentication daemon
#
# PROVIDE: authdaemond
# REQUIRE: LOGIN

if [ -f /etc/rc.subr ]; then
        . /etc/rc.subr
fi

name="authdaemond"
rcvar=${name}
daemon="@PREFIX@/libexec/courier/authlib/authdaemond"
pidfile="@AUTHDAEMONVAR@/pid"
required_files="@PKG_SYSCONFDIR@/authdaemonrc"

start_cmd="courier_doit start"
stop_cmd="courier_doit stop"

# Read the authdaemond config file to determine the actual command
# executed.  If "$version" is non-empty, then it contains the
# command name, otherwise, use the default of "authdaemond.plain".
# We read the config file in a subprocess to protect against shell
# environment pollution.
#
if [ -f @PKG_SYSCONFDIR@/authdaemonrc ]; then
	command=`
		. @PKG_SYSCONFDIR@/authdaemonrc
		if [ -n "${version}" ]; then
			@ECHO@ @PREFIX@/libexec/courier/authlib/${version}
		else
			@ECHO@ @PREFIX@/libexec/courier/authlib/authdaemond.plain
		fi
	`
fi

courier_doit()
{
        action=$1
        case ${action} in
        start)  echo "Starting ${name}." ;;
        stop)   echo "Stopping ${name}." ;;
        esac

        @SETENV@ -i ${daemon} ${action}
}

if [ -f /etc/rc.subr ]; then
        load_rc_config $name
        run_rc_command "$1"
else
        @ECHO@ -n " ${name}"
        ${start_cmd}
fi
