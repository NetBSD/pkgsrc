#!@RCD_SCRIPTS_DIR@
#
# $NetBSD: postfix.sh,v 1.1.1.1 2004/03/06 15:04:12 grant Exp $
#

# PROVIDE: mail
# REQUIRE: LOGIN
#	we make mail start late, so that things like .forward's are not
#	processed until the system is fully operational

. /etc/rc.subr

name="postfix"
rcvar=$name
required_files="@PKG_SYSCONFDIR@/main.cf"
start_precmd="postfix_precmd"
start_cmd="${name} "'${rc_arg}'
stop_cmd=$start_cmd
reload_cmd=$start_cmd
extra_commands="reload"
spooletcdir="/var/spool/${name}/etc"
required_dirs=$spooletcdir

postfix_precmd()
{
	# As this is called after the is_running and required_dir checks
	# are made in run_rc_command(), we can safely assume ${spooletcdir}
	# exists and postfix isn't running at this point (unless forcestart
	# is used).
	#

	for f in localtime resolv.conf services; do
		if [ -f /etc/$f ]; then
			cmp -s /etc/$f ${spooletcdir}/$f || \
			    cp -p /etc/$f ${spooletcdir}/$f
		fi
	done
}

load_rc_config $name
run_rc_command "$1"
