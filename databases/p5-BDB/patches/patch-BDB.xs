$NetBSD: patch-BDB.xs,v 1.1 2026/07/21 09:00:46 wiz Exp $

https://rt.cpan.org/Public/Bug/Display.html?id=178571

From: Jitka Plesnikova <jplesnik@redhat.com>
Co-authored-by: Claude Opus 4.6 (Anthropic AI)
Subject: Rename atfork_child to bdb_atfork_child to avoid collision with perl 5.43.2+

Perl 5.43.2 introduced Perl_atfork_child() as a new API function and
added a macro `atfork_child -> Perl_atfork_child` in embed.h. This
causes a build failure because BDB.xs defines its own static
atfork_child() function, which after macro expansion becomes a static
redeclaration of the non-static Perl_atfork_child.

Rename the local function to bdb_atfork_child to avoid the name
collision.

--- BDB.xs.orig	2016-02-02 04:27:15.000000000 +0000
+++ BDB.xs
@@ -986,7 +986,11 @@ static void atfork_parent (void)
   X_UNLOCK (wrklock);
 }
 
-static void atfork_child (void)
+/* Perl 5.43.2+ defines atfork_child as a macro expanding to
+ * Perl_atfork_child. Use a different name to avoid the collision.
+ */
+#undef atfork_child
+static void bdb_atfork_child (void)
 {
   bdb_req prv;
 
@@ -1441,7 +1445,7 @@ BOOT:
 
         create_respipe ();
 
-        X_THREAD_ATFORK (atfork_prepare, atfork_parent, atfork_child);
+        X_THREAD_ATFORK (atfork_prepare, atfork_parent, bdb_atfork_child);
         patch_errno ();
 }
 
