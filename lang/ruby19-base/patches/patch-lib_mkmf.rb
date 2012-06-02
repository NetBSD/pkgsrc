$NetBSD: patch-lib_mkmf.rb,v 1.1 2012/06/02 02:21:16 taca Exp $

Make sure to keep space; patch from Ruby's repository, r35698.

--- lib/mkmf.rb.orig	2010-05-29 00:43:09.000000000 +0000
+++ lib/mkmf.rb
@@ -1491,8 +1491,9 @@ LIBRUBY = #{CONFIG['LIBRUBY']}
 LIBRUBY_A = #{CONFIG['LIBRUBY_A']}
 LIBRUBYARG_SHARED = #$LIBRUBYARG_SHARED
 LIBRUBYARG_STATIC = #$LIBRUBYARG_STATIC
-OUTFLAG = #{OUTFLAG}
-COUTFLAG = #{COUTFLAG}
+empty =
+OUTFLAG = #{OUTFLAG}$(empty)
+COUTFLAG = #{COUTFLAG}$(empty)
 
 RUBY_EXTCONF_H = #{$extconf_h}
 cflags   = #{CONFIG['cflags']}
