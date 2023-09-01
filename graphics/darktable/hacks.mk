# $NetBSD: hacks.mk,v 1.3 2023/09/01 16:23:09 nia Exp $

.if !defined(DARKTABLE_HACKS_MK)
DARKTABLE_HACKS_MK:=

.  include "../../mk/bsd.fast.prefs.mk"
.  if ${OPSYS} == "NetBSD" && !empty(PKGSRC_COMPILER:M*gcc*)
PKG_HACKS+=		disable-graphite-opt
# Disable some of the more ridiculous compiler flags being used, that are
# creating build failures with the system compiler on NetBSD due to the
# assumption that the isl/graphite optimizer is available.
CFLAGS+=		-Wno-unknown-pragmas
SUBST_CLASSES+=		opt
SUBST_MESSAGE.opt=	Disabling excessive forced optimizations.
SUBST_STAGE.opt+=	pre-configure
SUBST_SED.opt+=		-e "s,pragma GCC optimize,pragma GCC nooptimize,g"
SUBST_FILES.opt+=	src/iop/*.c
SUBST_FILES.opt+=	src/iop/demosaicing/*.c
SUBST_FILES.opt+=	src/develop/blends/*.c
SUBST_FILES.opt+=	src/common/*.c
SUBST_FILES.opt+=	src/common/*.h
.  endif
.endif
