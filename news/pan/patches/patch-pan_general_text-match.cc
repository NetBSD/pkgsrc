$NetBSD: patch-pan_general_text-match.cc,v 1.1 2015/08/25 08:29:10 richard Exp $
Avoid clash with host defined ERR (on SunOS)
--- pan/general/text-match.cc.orig	2012-06-29 22:24:54.000000000 +0000
+++ pan/general/text-match.cc
@@ -209,7 +209,7 @@ TextMatch :: my_regexec (const StringVie
       if (_pcre_info->set (_impl_text, state.case_sensitive))
          _pcre_state = COMPILED;
       else
-         _pcre_state = ERR;
+         _pcre_state = PCRE_ERR;
    }
 
    return _pcre_state != COMPILED
