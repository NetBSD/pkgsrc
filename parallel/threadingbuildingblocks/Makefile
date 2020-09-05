# $NetBSD: Makefile,v 1.9 2020/09/05 11:34:07 ryoon Exp $

DISTNAME=	oneTBB-2020.3
PKGNAME=	${DISTNAME:S/oneTBB-/threadingbuildingblocks-/}
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_GITHUB:=oneapi-src/}
EXTRACT_SUFX=	.tar.gz
GITHUB_PROJECT=	oneTBB
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	https://www.threadingbuildingblocks.org/
COMMENT=	Threading Buildling Blocks

USE_LANGUAGES=	c c++
USE_TOOLS=	gmake pax
MAKE_FLAGS=	tbb_build_prefix=build # use fixed path
MAKE_FLAGS+=	native_compiler=${CC_VERSION:C/-[[:digit:]].*//}
MAKE_FLAGS+=	compiler=${CC_VERSION:C/-[[:digit:]].*//}
BUILD_TARGET=	default
TEST_TARGET=	test

pre-configure:
	cd ${WRKSRC}/build/ && cp FreeBSD.gcc.inc NetBSD.gcc.inc && cp FreeBSD.inc NetBSD.inc

INSTALLATION_DIRS=	include lib

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/build_release/libtbb.so ${DESTDIR}${PREFIX}/lib/
	${INSTALL_LIB} ${WRKSRC}/build/build_release/libtbbmalloc.so ${DESTDIR}${PREFIX}/lib/
	(cd ${WRKSRC}/include && pax -rw tbb ${DESTDIR}${PREFIX}/include/)
# documentation:
#	(cd $(WRKSRC)/doc/html && pax -rw . $(DESTDIR)$(PREFIX)/share/doc/html/$(PKGBASE)/)
#	$(INSTALL_DATA) $(WRKSRC)/doc/Release_Notes.txt $(DESTDIR)$(PREFIX)/share/doc/$(PKGBASE)/

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
