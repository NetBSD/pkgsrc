# $NetBSD: Makefile,v 1.69 2026/02/10 13:39:36 mef Exp $

DISTNAME=	qpdf-12.3.2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qpdf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://qpdf.sourceforge.io/
COMMENT=	Structural, content-preserving transformations on PDF files
LICENSE=	apache-2.0

# fix build on NetBSD/9.4
# -- Performing Test ATOMIC_WORKED0
# CMake Error in /tmp/print/qpdf/work/qpdf-12.3.2/cmake-pkgsrc-build/CMakeFiles/CMakeScratch/TryCompile-g61khV/CMakeLists.txt:
#   Target "cmTC_f6cd8" requires the language dialect "CXX20" .  But the
#   current compiler "GNU" does not support this, or CMake does not know the

USE_CXX_FEATURES+=	c++20
USE_LANGUAGES=		c c++
USE_TOOLS+=		perl:test pkg-config
PKGCONFIG_OVERRIDE+=	libqpdf.pc.in
TEST_TARGET=		test

CMAKE_CONFIGURE_ARGS+=		-DUSE_IMPLICIT_CRYPTO=OFF
CMAKE_CONFIGURE_ARGS+=		-DREQUIRE_CRYPTO_GNUTLS=OFF
CMAKE_CONFIGURE_ARGS+=		-DREQUIRE_CRYPTO_OPENSSL=ON
CMAKE_CONFIGURE_ARGS+=		-DDEFAULT_CRYPTO=openssl

.include "../../devel/cmake/build.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
