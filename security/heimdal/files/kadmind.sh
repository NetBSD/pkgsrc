#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: kadmind.sh,v 1.2 2005/12/21 04:17:49 jlam Exp $
#
# PROVIDE: kadmind
# REQUIRE: NETWORKING
# BEFORE:  SERVERS

. /etc/rc.subr

name="kadmind"
rcvar=$name
command="@PREFIX@/libexec/${name}"
command_args="& sleep 2"
required_files="@PKG_SYSCONFDIR@/krb5.conf"
required_vars="kdc"

# load_rc_config_var() from /etc/rc.subr on the netbsd-3 branch, for
# the benefit of platforms with older versions of /etc/rc.subr.
#
load_rc_config_var()
{
	eval $(eval '(
		load_rc_config '$1' >/dev/null;
		if [ -n "${'$2'}" -o "${'$2'-UNSET}" != "UNSET" ]; then
			echo '$2'=\'\''${'$2'}\'\'';
		fi
	)' )
}

load_rc_config $name
load_rc_config_var kdc kdc
run_rc_command "$1"
