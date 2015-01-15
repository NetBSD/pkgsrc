>Number:         49574
>Category:       pkg
>Synopsis:       security/pcsc-lite: add rc.d file, please
>Confidential:   no
>Severity:       non-critical
>Priority:       low
>Responsible:    pkg-manager
>State:          open
>Class:          change-request
>Submitter-Id:   net
>Arrival-Date:   Thu Jan 15 15:50:00 +0000 2015
>Originator:     ISIHARA Takanori
>Release:        pkgsrc -current 2015/1/16
>Organization:
Nagoya *BSD Users' Group :-)
>Environment:
NetBSD ishitPc9.home 6.1_STABLE NetBSD 6.1_STABLE (ISHITPC9) #21: Sun Sep 28 05:31:48 JST 2014  sysbuild@ishitPc9.home:/opt/sysbuild/netbsd-6/obj/i386/sys/arch/i386/compile/ISHITPC9 i386

>Description:
Please add "/usr/pkg/share/example/rc.d/pcscd" to install files.


>How-To-Repeat:

>Fix:
example rc.d file:

#!!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: pcscd.sh,v 1.1 2015/01/15 20:56:03 wiz Exp $
#

# PROVIDE: pcscd
# REQUIRE: DAEMON
# BEFORE:  LOGIN

$_rc_subr_loaded . /etc/rc.subr

name="pcscd"
rcvar=$name
command="@PREFIX@/sbin/${name}"

load_rc_config $name
run_rc_command "$1"

