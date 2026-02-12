$NetBSD: patch-src_gpacontext.h,v 1.1 2026/02/12 08:15:03 wiz Exp $

commit b6ba8bcc6db7765667cd6c49b7edc9a2073bc74f
Author: Werner Koch <wk@gnupg.org>
Date:   Fri Jul 18 09:45:23 2025 +0200

    Remove trust_item stuff to make it build with gpgme 2.x

--- src/gpacontext.h.orig	2018-10-16 19:58:08.000000000 +0000
+++ src/gpacontext.h
@@ -63,7 +63,6 @@ struct _GpaContextClass {
   void (*start) (GpaContext *context);
   void (*done) (GpaContext *context, gpg_error_t err);
   void (*next_key) (GpaContext *context, gpgme_key_t key);
-  void (*next_trust_item) (GpaContext *context, gpgme_trust_item_t item);
   void (*progress) (GpaContext *context, int current, int total);
 };
 
