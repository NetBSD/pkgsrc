$NetBSD: patch-br,v 1.1 2019/07/15 05:30:33 jnemeth Exp $

--- cf/m4/proto.m4.orig	2015-05-22 13:42:27.000000000 +0000
+++ cf/m4/proto.m4
@@ -695,6 +695,9 @@ _OPTION(MaxNOOPCommands, `confMAX_NOOP_C
 # Name to use for EHLO (defaults to $j)
 _OPTION(HeloName, `confHELO_NAME')
 
+# blacklistd
+_OPTION(UseBlacklist, `confUSE_BLACKLIST', `False')
+
 ifdef(`_NEED_SMTPOPMODES_', `dnl
 # SMTP operation modes
 C{SMTPOpModes} s d D')
