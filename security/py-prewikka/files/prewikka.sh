#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: prewikka.sh,v 1.2 2011/10/07 22:37:06 shattered Exp $
#

# PROVIDE: prewikka
# REQUIRE: mysqld LOGIN

$_rc_subr_loaded . /etc/rc.subr

name="prewikka"
rcvar=$name
required_files="@PKG_SYSCONFDIR@/prewikka/prewikka.conf"
start_precmd="prewikka_precommand"
command="@PREFIX@/sbin/runPrewikka -p 8080 -a 192.168.1.8"

prewikka_precommand()
{
	for i in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20; do
		if [ -S /tmp/mysql.sock ]; then
			break
		else
			sleep 1
			echo -n '.'
		fi
	done
}

load_rc_config $name
run_rc_command "$1"
