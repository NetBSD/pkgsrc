$NetBSD: patch-common-modified_gst-glib-gen.mak,v 1.1 2021/05/03 08:34:37 wiz Exp $

GNU Make 4.3 has a backwards incompatible change affecting the use of
number signs or hashes (ie., #) inside function invocations. See:
https://lists.gnu.org/archive/html/info-gnu/2020-01/msg00004.html

In this case, it would expand the '\#' in the '\n\#include \"$(h)\"'
argument to the foreach call to '\#', not '#'. This would lead to
spurious backslashes in front of the '#include' directives in the
generated fs-enumtypes.c file.

Spotted by Ernestas Kulik.

https://gitlab.freedesktop.org/farstream/farstream/-/commit/54987d445ea714b467d901b7daf8c09ed0644189

--- common-modified/gst-glib-gen.mak.orig	2020-03-11 21:05:08.000000000 +0000
+++ common-modified/gst-glib-gen.mak
@@ -6,7 +6,8 @@
 #glib_gen_prefix=gst_color_balance
 #glib_gen_basename=colorbalance
 
-enum_headers=$(foreach h,$(glib_enum_headers),\n\#include \"$(h)\")
+hash:=\#
+enum_headers=$(foreach h,$(glib_enum_headers),\n$(hash)include \"$(h)\")
 
 # these are all the rules generating the relevant files
 $(glib_gen_basename)-enumtypes.h: $(glib_enum_headers)
