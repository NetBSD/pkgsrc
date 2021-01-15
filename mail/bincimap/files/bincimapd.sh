#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: bincimapd.sh,v 1.1 2021/01/15 19:50:25 schmonz Exp $
#

# PROVIDE: bincimapd mail

name="bincimapd"

# User-settable rc.conf variables and their default values:
: ${bincimapd_postenv:=""}
: ${bincimapd_datalimit:="180000000"}
: ${bincimapd_pretcpserver:=""}
: ${bincimapd_tcpserver:="@PREFIX@/bin/tcpserver"}
: ${bincimapd_tcpflags:="-R -H"}
: ${bincimapd_tcphost:=":0"}
: ${bincimapd_tcpport:="143"}
: ${bincimapd_precheckpassword:="@PREFIX@/bin/bincimap-up --conf=@PKG_SYSCONFDIR@/bincimap.conf --"}
: ${bincimapd_checkpassword:="@PREFIX@/bin/nbcheckpassword"}
: ${bincimapd_preimapd:="@PREFIX@/bin/checknotroot"}
: ${bincimapd_imapdcmd:="@PREFIX@/bin/bincimapd"}
: ${bincimapd_postimapd:=""}

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

rcvar=${name}
required_files="@PKG_SYSCONFDIR@/bincimap.conf"
command="${bincimapd_tcpserver}"
procname=nb${name}
start_precmd="bincimapd_precmd"

bincimapd_precmd() {
	# tcpserver(1) is akin to inetd(8), but runs one service per process.
	# We want to signal only the tcpserver process responsible for this
	# service. Use argv0(1) to set procname to "nbbincimapd".
	command="@PREFIX@/bin/pgrphack @SETENV@ - ${bincimapd_postenv} \
@PREFIX@/bin/softlimit -m ${bincimapd_datalimit} ${bincimapd_pretcpserver} \
@PREFIX@/bin/argv0 ${bincimapd_tcpserver} ${procname} \
${bincimapd_tcpflags} \
${bincimapd_tcphost} ${bincimapd_tcpport} \
${bincimapd_precheckpassword} ${bincimapd_checkpassword} \
${bincimapd_preimapd} ${bincimapd_imapdcmd} ${bincimapd_postimapd}"
	command_args="&"
	rc_flags=""
}

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO_N@ " ${name}"
	bincimapd_precmd
	eval ${command} ${bincimapd_flags} ${command_args}
fi
