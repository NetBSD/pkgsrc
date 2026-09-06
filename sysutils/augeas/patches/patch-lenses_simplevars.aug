$NetBSD: patch-lenses_simplevars.aug,v 1.1 2026/09/06 18:44:01 bsiegert Exp $

Two entries in this filter.

Take over /etc/adduser.conf from Shellvars, which cannot read what
OpenBSD's adduser(8) writes and silently mis-reads Debian's; see
patch-lenses_shellvars.aug.  Sent upstream as hercules-team/augeas#893.

Fix the path of OpenBSD's wsconsctl.conf.  The entry has read
/etc/wsconsctlctl.conf since it was added upstream in aa3bc264 (2013), so
it has never matched anything.  What OpenBSD's /etc/rc applies is
/etc/wsconsctl.conf, one wsconsctl(8) variable assignment per line, which
this lens parses as it stands.  NetBSD is unaffected: it has
/etc/wscons.conf, a different file in a different format.  Sent upstream
as hercules-team/augeas#887.

--- lenses/simplevars.aug.orig
+++ lenses/simplevars.aug
@@ -44,8 +44,9 @@
            . incl "/etc/wgetrc"
            . incl "/etc/zabbix/*.conf"
            . incl "/etc/audit/auditd.conf"
+           . incl "/etc/adduser.conf"
            . incl "/etc/mixerctl.conf"
-           . incl "/etc/wsconsctlctl.conf"
+           . incl "/etc/wsconsctl.conf"
            . incl "/etc/ocsinventory/ocsinventory-agent.cfg"
 
 let xfm = transform lns filter
