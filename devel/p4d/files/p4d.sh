#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: p4d.sh,v 1.2 2002/09/20 02:01:56 grant Exp $
#
# Perforce SCM server
#
# PROVIDE: p4d
# REQUIRE: DAEMON

[ -f /etc/rc.subr ] && . /etc/rc.subr

name="p4d"
rcvar=${name}
command="@PREFIX@/sbin/p4d"
start_cmd="p4d_start"
license_cmd="p4d_license"
extra_commands="license"

p4d_start()
{
	p4d_run ${p4d_flags} -d -q
}

p4d_license()
{
	p4d_run -V
}

p4d_run()
{
	eval "@SU@ -m @P4USER@ -c 'umask 037; @SETENV@ - `p4d_getenv` ${command} $@'"
}

p4d_getenv()
{
	p4d_getenv_debug
	p4d_getenv_journalfile
	p4d_getenv_logfile
	p4d_getenv_port
	p4d_getenv_rootdir
	p4d_getenv_tmp
}

p4d_getenv_debug()
{
	# Possibly specify debug output
	# p4d default: none
	if [ ! -z ${P4DEBUG} ]; then
		@ECHO@ -n " P4DEBUG=${P4DEBUG}"
	fi
}

p4d_getenv_journalfile()
{
	# Possibly specify the journal file
	# p4d default: "journal" if it exists, else none
	if [ ! -z ${P4JOURNAL} ]; then
		@ECHO@ -n " P4JOURNAL=${P4JOURNAL}"
	fi
}

p4d_getenv_logfile()
{
	# Always specify the log file
	# p4d default: stderr
	if [ -z ${P4LOG} ]; then
		P4LOG=@P4LOG@
	fi
	@ECHO@ -n " P4LOG=${P4LOG}"
}

p4d_getenv_port()
{
	# Possibly specify the port number
	# p4d default: 1666
	if [ ! -z ${P4PORT} ]; then
		@ECHO@ -n " P4PORT=${P4PORT}"
	fi
}

p4d_getenv_rootdir()
{
	# Always specify the root dir
	# p4d default: working directory
	if [ -z ${P4ROOT} ]; then
		P4ROOT=@P4ROOT@
	fi
	@ECHO@ -n " P4ROOT=${P4ROOT}"
}

p4d_getenv_tmp()
{
	# Possibly specify temp dir
	# p4d default: /tmp
	if [ ! -z ${TEMP} ]; then
		@ECHO@ -n " TMP=${TEMP}"
	elif [ ! -z ${TMP} ]; then
		@ECHO@ -n " TMP=${TMP}"
	fi
}

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	echo -n " ${name}"
	${start_cmd}
fi
