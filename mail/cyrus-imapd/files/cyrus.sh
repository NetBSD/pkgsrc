#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: cyrus.sh,v 1.2 2002/09/20 02:01:57 grant Exp $
#
# PROVIDE: cyrus
# REQUIRE: DAEMON
#
# To start cyrus-imapd at startup, copy this script to /etc/rc.d and set
# cyrus=YES in /etc/rc.conf.

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

rcd_dir=`@DIRNAME@ $0`

name="cyrus"
rcvar=$name
command="@PREFIX@/cyrus/bin/master"
command_args="& sleep 2"
required_files="@PKG_SYSCONFDIR@/cyrus.conf @IMAPDCONF@"
extra_commands="mkimap reload"

mkimap_cmd="cyrus_mkimap"
start_precmd="cyrus_prestart"

cyrus_prestart()
{
	# Check to see if "configdirectory" is present before we start
	# the Cyrus IMAP server.  Otherwise, we run mkimap to generate
	# the necessary directories.
	#
	if [ -f @IMAPDCONF@ ]; then
		configdir=`						\
			@AWK@ '/^configdirectory:/ { print $2; exit };'	\
			      @IMAPDCONF@				\
		`
		if [ -z "$configdir" ]; then
			@ECHO@ "@IMAPDCONF@ missing 'configdirectory' setting"
			exit 1
		fi
		if [ ! -d "$configdir" ]; then
			$rcd_dir/cyrus mkimap
		fi
	fi
}

cyrus_mkimap()
{
	# Generate the prerequisite directory structure for Cyrus IMAP.
	if [ -f @IMAPDCONF@ ]; then
		imap_dirs=`
			@AWK@ '/^configdirectory:/	{ print $2 };	\
			       /^partition-.*:/		{ print $2 };	\
			       /^sievedir:/		{ print $2 }'	\
			      @IMAPDCONF@				\
		`
		for dir in ${imap_dirs}; do
			if [ ! -d ${dir} ]; then
				@MKDIR@ ${dir}
				@CHMOD@ 750 ${dir}
				@CHOWN@ @CYRUS_USER@ ${dir}
				@CHGRP@ @CYRUS_GROUP@ ${dir}
			fi
		done
		@SU@ -m @CYRUS_USER@ -c "@PREFIX@/cyrus/bin/mkimap"
	fi
}

if [ -f /etc/rc.subr -a -f /etc/rc.conf \
     -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	eval ${start_precmd}
	${command} ${cyrus_flags} ${command_args}
fi
