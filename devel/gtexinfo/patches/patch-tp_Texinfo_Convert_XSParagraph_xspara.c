$NetBSD: patch-tp_Texinfo_Convert_XSParagraph_xspara.c,v 1.1 2016/03/20 19:09:53 wiz Exp $

Do not call text_append_n with (size_t)-1.

--- tp/Texinfo/Convert/XSParagraph/xspara.c.orig	2016-01-23 11:31:17.000000000 +0000
+++ tp/Texinfo/Convert/XSParagraph/xspara.c
@@ -872,7 +872,7 @@ xspara_add_text (char *text)
                         {
                           if (state.space_counter > 0)
                             {
-                              /* Truncuate to at most 2 spaces, and replace any 
+                              /* Truncate to at most 2 spaces, and replace any 
                                  '\n' or '\r' characters with ' '. */
 
                               TEXT new_space;
@@ -892,12 +892,18 @@ xspara_add_text (char *text)
                                     break;
                                   len = mbrlen (pspace, pspace_left, NULL);
 
-                                  /* Subtitute newlines in the pending space
+                                  /* Substitute newlines in the pending space
                                      with spaces. */
                                   if (*pspace == '\n' || *pspace == '\r')
                                     text_append_n (&new_space, " ", 1);
-                                  else
-                                    text_append_n (&new_space, pspace, len);
+                                  else {
+                                    if (len > 0) {
+                                      text_append_n (&new_space, pspace, len);
+                                    } else {
+                                      /* skip one character and try again */
+                                      len = 1;
+                                    }
+                                  }
                                   state.space_counter++;
 
                                   pspace += len;
