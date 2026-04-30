# $NetBSD: Makefile,v 1.16 2026/04/30 12:22:57 adam Exp $

DISTNAME=	mimalloc-3.3.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=microsoft/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/microsoft/mimalloc
COMMENT=	General-purpose allocator with excellent performance characteristics
LICENSE=	mit

USE_CC_FEATURES=	c11
USE_CXX_FEATURES=	c++17
USE_LANGUAGES=		c c++
TEST_ENV+=		LD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}
# For Darwin
TEST_ENV+=		DYLD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}
TEST_TARGET=		test
# For building tests.
LDFLAGS.NetBSD+=	-lpthread

CMAKE_CONFIGURE_ARGS+=	-DMI_INSTALL_TOPLEVEL=ON

INSTALLATION_DIRS+=	lib/cmake/mimalloc

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/lib/mimalloc.o

.include "../../devel/cmake/build.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
