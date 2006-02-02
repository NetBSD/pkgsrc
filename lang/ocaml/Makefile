# $NetBSD: Makefile,v 1.44 2006/02/02 20:47:26 rillig Exp $

.include "Makefile.common"

PKGREVISION=		1

CONFIGURE_ARGS+=	-no-tk
CONFIGURE_ENV+=		disable_x11=yes

BUILD_TARGET=		world
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc")
BUILD_TARGET+=	opt opt.opt
PLIST_SRC=	${PKGDIR}/PLIST.opt
.  if (${OPSYS} != "Darwin") && \
      !(${OPSYS} == "SunOS" && ${MACHINE_ARCH} == "i386") && \
      !(${OPSYS} == "NetBSD" && ${MACHINE_ARCH} == "sparc")
PLIST_SRC+=	${PKGDIR}/PLIST.prof
.  endif
PLIST_SRC+=	${PKGDIR}/PLIST
.endif

.if ${OPSYS} == "Darwin" || ${OPSYS} == "DragonFly" || ${OPSYS} == "NetBSD"
PLIST_SRC+=	${PKGDIR}/PLIST.stub
.endif

.include "../../mk/bsd.pkg.mk"
