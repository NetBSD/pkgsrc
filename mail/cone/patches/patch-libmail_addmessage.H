$NetBSD: patch-libmail_addmessage.H,v 1.1 2020/03/22 21:24:56 joerg Exp $

--- libmail/addmessage.H.orig	2020-03-22 20:23:21.658486107 +0000
+++ libmail/addmessage.H
@@ -39,7 +39,7 @@ class Attachment;
 // notification).
 
 
-class addMessage : private ptr<mail::account> {
+class addMessage : public ptr<mail::account> {
 
 protected:
 	bool checkServer();
