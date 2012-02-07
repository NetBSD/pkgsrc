#!@RCD_SCRIPTS_SHELL@
#
#      $NetBSD: pure_uploadscript.sh,v 1.1 2012/02/07 20:40:39 morr Exp $
#
# PROVIDE: pure_uploadscript
# REQUIRE: pure_ftpd

. /etc/rc.subr

name="pure_uploadscript"
help_name="pure-uploadscript"
rcvar=$name
required_vars="pure_ftpd"
command="@PREFIX@/sbin/${help_name}"
command_args="-B"
start_precmd=pure_uploadscript_precmd

pure_uploadscript_precmd()
{
       is_uploadscript_enabled=0
       for opt in ${pure_ftpd_flags}
       do
               if [ "x${opt}" = "x-o" -o "x${opt}" = "x--uploadscript"]; then
                       is_uploadscript_enabled=1
               fi
       done

       if [ ${is_uploadscript_enabled} -eq 0 ]; then
               echo "WARNING: uploadscript for pure-ftpd is not enabled"
               return 1
       fi
}

load_rc_config $name
run_rc_command "$1"
