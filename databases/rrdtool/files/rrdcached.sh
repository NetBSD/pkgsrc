#!@RCD_SCRIPTS_SHELL@
#
# PROVIDE: rrdcached
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="rrdcached"
rcvar=${name}
command="@PREFIX@/bin/${name}"
pidfile="@VARBASE@/run/${name}/${name}.pid"
sockfile="/var/run/${name}/${name}.sock"
start_precmd="rrdcached_precmd"

rrdcached_precmd()
{
	rc_flags="-p ${pidfile} -l ${sockfile} -U rrdcached $rc_flags"

	local piddir="$(dirname "${pidfile}")"
	mkdir -p "${piddir}"
	chown rrdcached:rrdcached "${piddir}"
}

load_rc_config $name
run_rc_command "$1"
