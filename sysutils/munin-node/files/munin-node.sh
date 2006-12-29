#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: munin-node.sh,v 1.4 2006/12/29 06:37:03 obache Exp $
#
# PROVIDE: munin-node
# REQUIRE: DAEMON
# KEYWORD: shutdown
#
# You will need to set some variables in /etc/rc.conf to start munin-node:
#
# munin_node=YES
#

if [ -f /etc/rc.subr ]
then
    . /etc/rc.subr
fi

name="munin_node"
rcvar=$name
command=@PREFIX@/sbin/munin-node
command_interpreter=@PERL@
pidfile="@VARBASE@/run/munin/munin-node.pid"
required_files=@PKG_SYSCONFDIR@/munin-node.conf

stop_cmd="munin_node_stop"

# Net::Server breaks rc.subr's techniques for detecting whether the
# process running at a certain PID is actually the process we wish to
# stop.  Just unconditionally send SIGTERM to the PID instead.
#
munin_node_stop()
{
	@ECHO@ "Stopping ${name}."
	if [ -f ${pidfile} ]; then
		pid=`@HEAD@ -1 ${pidfile}`
		doit="kill ${pid}"
		if ! eval $doit && [ -z "$rc_force" ]; then
			return 1
		fi
		wait_for_pids $pid
	fi
	@RM@ -f ${pidfile}
}

if [ ! -d @STATEDIR@ ]; then
	mkdir @STATEDIR@
	chown @MUNIN_USER@:@MUNIN_GROUP@ @STATEDIR@
fi
if [ ! -d @MUNIN_RUN@ ]; then
	mkdir @MUNIN_RUN@
	chown @MUNIN_USER@:@MUNIN_GROUP@ @MUNIN_RUN@
fi

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	echo -n " ${name}"
	exec ${command} ${command_args}
fi
