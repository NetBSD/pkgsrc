$NetBSD: patch-mkc__imp.init.mk,v 1.1 2011/05/13 22:00:26 cheusov Exp $

--- mkc_imp.init.mk.orig	2010-10-23 14:18:27.000000000 +0000
+++ mkc_imp.init.mk
@@ -13,7 +13,7 @@ TARGET_OPSYS?=  ${OPSYS}
 .ifdef DPLIBDIRS
 .for _dir in ${DPLIBDIRS}
 .ifndef DPLIBDIRS.${_dir:T}
-DPLIBDIRS.${_dir:T}!= 	cd ${_dir} && ${MAKE} ${MAKEFLAGS} mkc_printobjdir
+DPLIBDIRS.${_dir:T}!= 	cd ${_dir} && ${MAKE} ${MAKEFLAGS} -j1 mkc_printobjdir
 .if ${TARGET_OPSYS} == "HP-UX"
 LDFLAGS+=		${CFLAGS.cctold}+b ${CFLAGS.cctold}${LIBDIR}
 .endif
