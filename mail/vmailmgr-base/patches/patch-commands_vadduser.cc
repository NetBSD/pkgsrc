$NetBSD: patch-commands_vadduser.cc,v 1.1 2024/02/25 12:09:22 schmonz Exp $

Avoid dangling else.

--- commands/vadduser.cc.orig	2024-02-22 18:36:02.894040336 +0000
+++ commands/vadduser.cc
@@ -190,16 +190,18 @@ void add_alias(mystring user, mystring a
   if(!domain.exists(alias)) {
     vpwentry vpw(alias, "*", domain.userdir(alias), user, false);
     response resp = domain.set(&vpw, true);
-    if(!resp)
+    if(!resp) {
       if(!o_quiet)
 	ferr << argv0base << ": warning: adding the alias '"
 	     << alias
 	     << "' failed:\n  "
 	     << resp.msg << endl;
-    else
+    }
+    else {
       if(!o_quiet)
 	fout << argv0base << ": alias '" << alias << "' successfully added"
 	     << endl;
+    }
   }
   else
     if(!o_quiet)
