#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: gitea-runner.sh,v 1.1 2026/08/30 16:55:23 khorben Exp $
#
# PROVIDE: gitea-runner
# REQUIRE: DAEMON
#
# You will need to set some variables in @SYSCONFBASE@/rc.conf to start gitea-runner:
#
# gitea_runner=YES

$_rc_subr_loaded . @SYSCONFBASE@/rc.subr

name="gitea_runner"
rcvar=${name}
required_files="@PKG_SYSCONFDIR@/config.yaml"
command="@PREFIX@/bin/gitea-runner"
command_args="--config @PKG_SYSCONFDIR@/config.yaml daemon > /dev/null &"

gitea_runner_user="@GITEA_RUNNER_USER@"
gitea_runner_group="@GITEA_RUNNER_GROUP@"

cd /

load_rc_config $name
run_rc_command "$1"
