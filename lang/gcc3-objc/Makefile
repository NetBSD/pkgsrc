# $NetBSD: Makefile,v 1.6 2003/08/11 14:16:06 drochner Exp $
#

PKGNAME=		gcc3${GCC3_PKGMODIF}-objc-${GCC_VERSION}
COMMENT=		GNU Compiler Collection, version 3, objc compiler

.include "../gcc3-c/buildaddon.mk"

CONFIGURE_ARGS+=	--enable-languages="objc"

do-build:
	(cd ${WRKSRC}/gcc && ${SETENV} ${MAKE_ENV} ${GMAKE} objc)
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} all-target-libobjc)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gcc/cc1obj ${GCC_ARCHDIR}
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		install-target-libobjc)

.include "../../mk/bsd.pkg.mk"
