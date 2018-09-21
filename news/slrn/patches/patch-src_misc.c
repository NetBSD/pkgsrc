$NetBSD: patch-src_misc.c,v 1.1 2018/09/21 14:27:37 wiz Exp $

Added default value for new config option "canlock_algo".

--- src/misc.c.orig	2016-10-23 22:34:16.000000000 +0000
+++ src/misc.c
@@ -2828,6 +2828,8 @@ void slrn_get_user_info (void) /*{{{*/
 
 #if SLRN_HAS_CANLOCK
    Slrn_User_Info.cancelsecret = slrn_safe_strmalloc ("");
+   /* SHA256 ist the mandatory algorithm defined by RFC 8315 */
+   Slrn_User_Info.canlock_algo = slrn_safe_strmalloc ("SHA256");
 #endif
 #ifdef SLRN_SENDMAIL_COMMAND
    Slrn_SendMail_Command = slrn_safe_strmalloc (SLRN_SENDMAIL_COMMAND);
