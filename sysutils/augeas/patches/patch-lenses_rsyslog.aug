$NetBSD: patch-lenses_rsyslog.aug,v 1.1 2026/09/06 18:44:01 bsiegert Exp $

Add the /usr/local paths, which are missing from three filters.

On the BSDs rsyslog is configured under /usr/local/etc, as software the
system did not ship itself.  Dovecot, Nginx, Php, Postfix, Puppet,
Sudoers and Systemd already carry their /usr/local counterpart; Rsyslog
does not.

Sent upstream as hercules-team/augeas#888; this is that diff.

--- lenses/rsyslog.aug.orig
+++ lenses/rsyslog.aug
@@ -93,6 +93,8 @@ let lns = entries . ( program | hostname )*
 
 let filter = incl "/etc/rsyslog.conf"
            . incl "/etc/rsyslog.d/*"
+           . incl "/usr/local/etc/rsyslog.conf"
+           . incl "/usr/local/etc/rsyslog.d/*"
            . Util.stdexcl
 
 let xfm = transform lns filter
