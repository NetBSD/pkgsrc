$NetBSD: patch-lenses_shellvars.aug,v 1.1 2026/09/06 18:44:01 bsiegert Exp $

Do not read /etc/adduser.conf as a shell script.

Of the three systems that ship the file, only FreeBSD treats it as one.
OpenBSD's adduser(8) is perl and evals each line, so what it writes is
perl and this lens fails on it outright.  Debian's is perl too and allows
whitespace around the equals sign, which this lens does not reject but
reads as a command, so the setting disappears without an error.  NetBSD
has no adduser(8); useradd(8) reads /etc/usermgmt.conf instead.

Simplevars accepts all three; see patch-lenses_simplevars.aug.

Sent upstream as hercules-team/augeas#893; this is that diff.

--- lenses/shellvars.aug.orig
+++ lenses/shellvars.aug
@@ -305,7 +305,6 @@
                      . incl "/etc/environment"
                      . incl "/etc/firewalld/firewalld.conf"
                      . incl "/etc/blkid.conf"
-                     . incl "/etc/adduser.conf"
                      . incl "/etc/cowpoke.conf"
                      . incl "/etc/cvs-cron.conf"
                      . incl "/etc/cvs-pserver.conf"
