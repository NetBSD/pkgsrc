# $NetBSD: Makefile,v 1.2 2020/01/26 17:31:28 rillig Exp $

VERS=		6.0.0
DISTNAME=	compiler-rt-${VERS}.src
PKGNAME=	libBlocksRuntime-${VERS}
CATEGORIES=	lang devel
MASTER_SITES=	https://releases.llvm.org/${VERS}/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://compiler-rt.llvm.org/
COMMENT=	Runtime support for Apple Blocks
LICENSE=	mit

EXTRACT_SUFX=	.tar.xz

USE_LANGUAGES=	c
USE_LIBTOOL=	yes

INSTALLATION_DIRS+=	include lib

do-build:
	cd ${WRKSRC}/lib/BlocksRuntime && ${SETENV} ${MAKE_ENV} \
	    ${LIBTOOL} --mode=compile ${COMPILE.c} data.c
	cd ${WRKSRC}/lib/BlocksRuntime && ${SETENV} ${MAKE_ENV} \
	    ${LIBTOOL} --mode=compile ${COMPILE.c} runtime.c
	cd ${WRKSRC}/lib/BlocksRuntime && ${SETENV} ${MAKE_ENV} \
	    ${LIBTOOL} --mode=link ${LINK.c} -o libBlocksRuntime.la \
	    data.lo runtime.lo -version-info 1:0:0 -rpath ${PREFIX}/lib

do-install:
	${SETENV} ${MAKE_ENV} ${LIBTOOL} --mode=install ${INSTALL_LIB} \
	    ${WRKSRC}/lib/BlocksRuntime/libBlocksRuntime.la \
		${DESTDIR}${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/lib/BlocksRuntime/Block.h \
		${DESTDIR}${PREFIX}/include/

.include "../../mk/bsd.pkg.mk"
