# $NetBSD: Makefile,v 1.38 2005/06/14 21:00:41 minskim Exp $

.include "Makefile.common"

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

.if ${OPSYS} == "Darwin"
PLIST_SRC+=	${PKGDIR}/PLIST.stub
.endif

.include "../../mk/bsd.pkg.mk"
