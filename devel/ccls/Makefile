# $NetBSD: Makefile,v 1.7 2024/05/29 16:31:58 adam Exp $

DISTNAME=	ccls-0.20230717
MASTER_SITES=	${MASTER_SITE_GITHUB:=MaskRay/}
PKGREVISION=	2
CATEGORIES=	devel
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/MaskRay/ccls
COMMENT=	C/C++/ObjC language server
LICENSE=	apache-2.0

USE_CXX_FEATURES+=	c++17
USE_LANGUAGES=		c c++
CMAKE_CONFIGURE_ARGS+=	-DCCLS_VERSION:STRING="${PKGVERSION_NOREV}"

CXXFLAGS+=	-DNDEBUG

PTHREAD_OPTS+=	require
.include "../../mk/pthread.buildlink3.mk"

# Package builds with clang specific switches
PKGSRC_COMPILER=	clang
PKG_CC=			clang
PKG_CXX=		clang++

.include "../../archivers/zstd/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/rapidjson/buildlink3.mk"
.include "../../mk/terminfo.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
