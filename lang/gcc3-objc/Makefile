# $NetBSD: Makefile,v 1.7 2004/02/01 14:05:47 jlam Exp $

PKGNAME=	gcc3${GCC3_PKGMODIF}-objc-${GCC_VERSION}
COMMENT=	GNU Compiler Collection, v3 - Objective C compiler

.include "../gcc3-c/language.mk"

CONFIGURE_ARGS+=	--enable-languages="objc"

do-build:
	cd ${WRKSRC}/gcc && ${SETENV} ${MAKE_ENV} ${GMAKE} objc
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} all-target-libobjc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gcc/cc1obj ${GCC_ARCHDIR}
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		install-target-libobjc

.include "../../mk/bsd.pkg.mk"
