# $NetBSD: Makefile,v 1.9 2004/03/02 14:46:33 drochner Exp $

PKGNAME=	gcc3${GCC3_PKGMODIF}-objc-${GCC_VERSION}
COMMENT=	GNU Compiler Collection, v3 - Objective C compiler

INSTLIBS=	libobjc/libobjc.la

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
