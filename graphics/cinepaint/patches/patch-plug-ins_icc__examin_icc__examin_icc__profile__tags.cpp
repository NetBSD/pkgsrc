$NetBSD: patch-plug-ins_icc__examin_icc__examin_icc__profile__tags.cpp,v 1.1 2016/12/22 21:03:12 joerg Exp $

Pointers have no sign.

--- plug-ins/icc_examin/icc_examin/icc_profile_tags.cpp.orig	2016-12-22 13:23:55.102285480 +0000
+++ plug-ins/icc_examin/icc_examin/icc_profile_tags.cpp
@@ -332,12 +332,12 @@ ICCtag::getText                     (voi
 #   ifdef DEBUG_ICCTAG
     DBG_NUM_S ((int)strchr(txt, 13))
 #   endif
-    while (strchr(txt, 13) > 0) { // \r 013 0x0d
+    while (strchr(txt, 13)) { // \r 013 0x0d
       pos = strchr(txt, 13);
 #     ifdef DEBUG_ICCTAG
       //cout << (int)pos << " "; DBG
 #     endif
-      if (pos > 0) {
+      if (pos) {
         if (*(pos+1) == '\n')
           *pos = ' ';
         else
