# $NetBSD: Makefile,v 1.35 2004/12/24 17:16:04 jmmv Exp $

.include "Makefile.common"

PKGREVISION=	8

CONFIGURE_ARGS+=	-no-tk
CONFIGURE_ENV+=		disable_x11=yes

BUILD_TARGET=		world
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc")
BUILD_TARGET+=	opt opt.opt
PLIST_SRC=	${PKGDIR}/PLIST.opt
.  if ${OPSYS} != "Darwin"
PLIST_SRC+=	${PKGDIR}/PLIST.prof
.  endif
PLIST_SRC+=	${PKGDIR}/PLIST
.endif

.include "../../mk/bsd.pkg.mk"
