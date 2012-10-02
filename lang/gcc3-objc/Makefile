# $NetBSD: Makefile,v 1.17 2012/10/02 20:11:40 asau Exp $

PKGNAME=	gcc3${GCC3_PKGMODIF}-objc-${GCC_VERSION}
COMMENT=	GNU Compiler Collection, v3 - Objective C compiler
PKGREVISION=	1

INSTLIBS=	libobjc/libobjc.la
MAKE_ENV+=	DESTDIR=${DESTDIR}

.include "../../lang/gcc3/language.mk"

CONFIGURE_ARGS+=	--enable-languages="objc"

do-build:
	cd ${WRKSRC}/gcc && ${SETENV} ${MAKE_ENV} ${GMAKE} objc
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} all-target-libobjc

do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${GCC_ARCHDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/gcc/cc1obj ${DESTDIR}${GCC_ARCHDIR}
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		install-target-libobjc

.include "../../mk/bsd.pkg.mk"
