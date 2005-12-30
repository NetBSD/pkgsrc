#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: postfix.sh,v 1.3.12.1 2005/12/30 13:58:14 seb Exp $
#

# PROVIDE: mail
# REQUIRE: LOGIN
#	we make mail start late, so that things like .forward's are not
#	processed until the system is fully operational

. /etc/rc.subr

name="postfix"
rcvar=$name
postfix_command="@PREFIX@/sbin/${name}"
: ${required_files=`@PREFIX@/sbin/postconf -h config_directory`/main.cf}
start_precmd="postfix_precmd"
start_cmd="postfix_op"
stop_cmd="postfix_op"
reload_cmd="postfix_op"
extra_commands="reload"
: ${spooletcdir=`@PREFIX@/sbin/postconf -h queue_directory`/etc}
required_dirs=$spooletcdir

postfix_precmd()
{
	# As this is called after the is_running and required_dir checks
	# are made in run_rc_command(), we can safely assume ${spooletcdir}
	# exists and postfix isn't running at this point (unless forcestart
	# is used).
	#

	[ ! -d ${spooletcdir} ] && mkdir -p ${spooletcdir}
	for f in localtime resolv.conf services; do
		if [ -f /etc/$f ]; then
			cmp -s /etc/$f ${spooletcdir}/$f || \
			    cp -p /etc/$f ${spooletcdir}/$f
		fi
	done
}

postfix_op()
{
	case ${rc_arg} in
	start)
		for _f in $required_dirs; do
			if [ ! -d "${_f}/." ]; then
				warn "${_f} is not a directory."
				if [ -z $rc_force ]; then
					return 1
				fi
			fi
		done
		for _f in $required_files; do
			if [ ! -r "${_f}" ]; then
				warn "${_f} is not readable."
				if [ -z $rc_force ]; then
					return 1
				fi
			fi
		done
		${postfix_command} ${rc_arg}
		;;
	*)
		${postfix_command} ${rc_arg}
		;;
	esac
}

load_rc_config $name
run_rc_command "$1"
