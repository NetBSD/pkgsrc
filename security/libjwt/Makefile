# $NetBSD: Makefile,v 1.9 2026/03/11 11:03:01 adam Exp $

DISTNAME=	libjwt-3.3.2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=benmcollins/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/benmcollins/libjwt
COMMENT=	JWT C library
LICENSE=	mpl-2.0

TOOL_DEPENDS+=	doxygen>0:../../devel/doxygen

USE_LANGUAGES=		c c++
USE_TOOLS+=		bash pkg-config
CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=ON
CMAKE_CONFIGURE_ARGS+=	-DWITH_GNUTLS=OFF

TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}
# For Darwin
TEST_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}
TEST_TARGET=	test

SUBST_CLASSES+=		bashpath
SUBST_STAGE.bashpath=	pre-configure
SUBST_MESSAGE.bashpath=	Fixing path to bash.
SUBST_FILES.bashpath=	CMakeLists.txt
SUBST_SED.bashpath=	-e 's,/bin/bash,${BASH},g'

# for tests
.include "../../devel/check/buildlink3.mk"
.include "../../devel/cmake/build.mk"
BUILDLINK_API_DEPENDS.openssl+=	openssl>=3
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/jansson/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
