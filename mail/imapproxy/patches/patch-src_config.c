$NetBSD: patch-src_config.c,v 1.3 2020/04/16 14:03:29 manu Exp $

SASL PLAIN Support. Patch submitted upstream
http://sourceforge.net/tracker/?func=detail&aid=3610674&group_id=311&atid=300311

--- src/config.c.orig	2010-02-20 18:16:58.000000000 +0100
+++ src/config.c	2013-04-15 12:00:50.000000000 +0200
@@ -452,8 +452,11 @@
 		  &PC_Struct.force_tls, index );
 
     ADD_TO_TABLE( "enable_admin_commands", SetBooleanValue,
 		  &PC_Struct.enable_admin_commands, index );
+
+    ADD_TO_TABLE( "auth_sasl_mech", SetStringValue,
+		  &PC_Struct.auth_sasl_mech, index );
     
     ConfigTable[index].Keyword[0] = '\0';
     
     FP = fopen( ConfigFile, "r" );
