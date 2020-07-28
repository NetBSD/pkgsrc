$NetBSD: patch-core_src_dird_authenticate__console.cc,v 1.1 2020/07/28 06:36:29 kardel Exp $

	Remove inadequate clutter in production messages

--- core/src/dird/authenticate_console.cc.orig	2020-04-16 08:31:41.000000000 +0000
+++ core/src/dird/authenticate_console.cc
@@ -216,10 +216,12 @@ bool ConsoleAuthenticatorFrom_18_2::Send
 bool ConsoleAuthenticatorFrom_18_2::SendInfoMessage()
 {
   std::string message;
+#ifndef NO_ADV
   message += kBareosVersionStrings.BinaryInfo;
   message += " binary\n";
   message += kBareosVersionStrings.ServicesMessage;
   message += "\n";
+#endif
   message += "You are ";
   if (ua_->user_acl) {
     message += "logged in as: ";
