#!/bin/sh
#
# $NetBSD: znc.sh,v 1.1 2018/12/16 02:05:24 nia Exp $
#
# RC-script for znc 1.0
#

# PROVIDE: znc
# REQUIRE: NETWORKING
# KEYWORD: shutdown

${_rc_subr_loaded} . /etc/rc.subr

name="znc"
rcvar="${name}"
command="@PREFIX@/bin/${name}"
saveconf_cmd="${name}_saveconf"
makeconf_cmd="${name}_makeconf"

conf_dir="@PKG_SYSCONFDIR@"
conf_file="${conf_dir}/configs/${name}.conf"

sig_saveconf="-USR1"

required_files="${conf_file}"
extra_commands="reload saveconf makeconf"
command_args="-d ${conf_dir}"

znc_saveconf(){
        pids="$(check_process ${command})"
        if [ -n "$pids" ]; then
                echo -n "Saving znc config files"
                for pid in $pids; do
                        kill $sig_saveconf $pid
                done
                echo "."
        fi
}

znc_makeconf(){
	su -m ${znc_user} -c ${command} -d ${conf_dir} -r --makeconf
}

load_rc_config "${name}"
run_rc_command "${1}"
