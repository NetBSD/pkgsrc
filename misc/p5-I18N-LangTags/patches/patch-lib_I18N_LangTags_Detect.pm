$NetBSD: patch-lib_I18N_LangTags_Detect.pm,v 1.1 2013/04/07 02:36:22 markd Exp $

defined() on aggregates is deprecated.

--- lib/I18N/LangTags/Detect.pm.orig	2004-06-21 05:47:55.000000000 +0000
+++ lib/I18N/LangTags/Detect.pm
@@ -137,7 +137,7 @@ sub _try_use {   # Basically a wrapper a
   my $module = $_[0];   # ASSUME sane module name!
   { no strict 'refs';
     return($tried{$module} = 1)
-     if defined(%{$module . "::Lexicon"}) or defined(@{$module . "::ISA"});
+     if (%{$module . "::Lexicon"}) or (@{$module . "::ISA"});
     # weird case: we never use'd it, but there it is!
   }
 
