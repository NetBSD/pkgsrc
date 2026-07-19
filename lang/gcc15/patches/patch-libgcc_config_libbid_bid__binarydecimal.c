$NetBSD: patch-libgcc_config_libbid_bid__binarydecimal.c,v 1.1 2026/07/19 11:17:45 adam Exp $

Support Darwin/aarch64.
https://github.com/Homebrew/homebrew-core/blob/main/Patches/gcc/gcc-15.3.0.diff

--- libgcc/config/libbid/bid_binarydecimal.c.orig	2026-06-12 06:09:10.034578818 +0000
+++ libgcc/config/libbid/bid_binarydecimal.c
@@ -412,7 +412,7 @@ BID_BINARY80LDOUBLE;
 }

 #define unpack_binary80(x,s,e,c,t,zero,inf,nan)                             \
-{ BID_BINARY80LDOUBLE x_in;                                                 \
+{ BID_BINARY80LDOUBLE x_in = {0};                                                 \
   x_in.f = x;                                                               \
   c = x_in.i.lo4 + ((UINT64)x_in.i.lo3 << 16) +                             \
       ((UINT64)x_in.i.lo2 << 32) + ((UINT64)x_in.i.lo1 << 48);              \
