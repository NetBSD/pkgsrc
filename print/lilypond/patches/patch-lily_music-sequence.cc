$NetBSD: patch-lily_music-sequence.cc,v 1.1 2012/12/15 10:01:20 marino Exp $

Broken on gcc4.6+, patch taken from upstream (2011-12-09):
  Fix issue 2089: dangerous redefinition of SCM s / Moment s

--- lily/music-sequence.cc.orig	2011-07-25 22:42:15.000000000 +0000
+++ lily/music-sequence.cc
@@ -143,17 +143,15 @@ Music_sequence::minimum_start (SCM l)
 Moment
 Music_sequence::first_start (SCM l)
 {
-  Moment m;
 
   for (SCM s = l; scm_is_pair (s); s = scm_cdr (s))
     {
       Music *mus = unsmob_music (scm_car (s));
-      Moment l = mus->get_length ();
-      Moment s = mus->start_mom ();
-      if (l.to_bool () || s.to_bool ())
-	return s;
+      Moment start = mus->start_mom ();
+      if (mus->get_length ().to_bool() || start.to_bool())
+        return start;
     }
-  return m;
+  return Moment ();
 }
 
 MAKE_SCHEME_CALLBACK (Music_sequence, simultaneous_relative_callback, 2);
