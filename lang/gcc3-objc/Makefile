# $NetBSD: Makefile,v 1.4 2003/07/16 20:24:00 drochner Exp $
#

PKGNAME=		gcc3${GCC3_PKGMODIF}-objc-3.3
COMMENT=		GNU Compiler Collection, objc Compiler

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
