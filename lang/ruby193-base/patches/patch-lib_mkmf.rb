$NetBSD: patch-lib_mkmf.rb,v 1.1 2012/06/02 02:23:33 taca Exp $

Make sure to keep space; patch from Ruby's repository, r35698.

--- lib/mkmf.rb.orig	2012-02-17 04:24:39.000000000 +0000
+++ lib/mkmf.rb
@@ -1687,8 +1687,9 @@ LIBRUBY = #{CONFIG['LIBRUBY']}
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
