$NetBSD: patch-libgnomeui-gnome_scores.h,v 1.1 2017/10/19 23:05:43 jaapb Exp $

glib-mkenums expects input files to be UTF-8
(see https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=870729 ))
--- libgnomeui/gnome-scores.h.orig	2009-04-24 20:14:57.000000000 +0000
+++ libgnomeui/gnome-scores.h
@@ -27,7 +27,7 @@
  * "High Scores" Widget 
  *
  * AUTHOR: 
- * Horacio J. Peña <horape@compendium.com.ar>
+ * Horacio J. PeÃ±a <horape@compendium.com.ar>
  *
  * This is free software (under the terms of the GNU LGPL)
  *
