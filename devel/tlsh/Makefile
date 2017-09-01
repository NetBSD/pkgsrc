# $NetBSD: Makefile,v 1.2 2017/09/01 07:52:02 wiz Exp $

PKGREVISION=	1
USE_CMAKE=	yes
CONFIGURE_DIRS=	build/release
CMAKE_ARG_PATH=	../..
USE_LANGUAGES=	c c++
# all tests fail
#TEST_TARGET=	test

INSTALLATION_DIRS=	bin include lib

post-extract:
	mkdir ${WRKSRC}/build/release

do-install:
	${INSTALL_DATA} ${WRKSRC}/bin/tlsh_unittest ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/lib/libtlsh* ${DESTDIR}${PREFIX}/lib

.include "Makefile.common"
.include "../../mk/bsd.pkg.mk"
