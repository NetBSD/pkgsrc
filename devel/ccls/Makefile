# $NetBSD: Makefile,v 1.4 2023/05/02 06:47:25 nikita Exp $

DISTNAME=	ccls-0.20220729
MASTER_SITES=	${MASTER_SITE_GITHUB:=MaskRay/}
PKGREVISION=	1
CATEGORIES=	devel
GITHUB_TAG=	${PKGVERSION_NOREV}
GITHUB_PROJECT=	ccls

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/MaskRay/ccls
COMMENT=	C/C++/ObjC language server
LICENSE=	apache-2.0

USE_LANGUAGES=	c c++17
USE_CMAKE=	yes
CMAKE_ARGS+=	-DCCLS_VERSION:STRING="${PKGVERSION_NOREV}"
CXXFLAGS+=	-DNDEBUG

PTHREAD_OPTS+=	require
.include "../../mk/pthread.buildlink3.mk"

# Package builds with clang specific switches
PKGSRC_COMPILER=	clang
PKG_CC=			clang
PKG_CXX=		clang++

DEPENDS+=	llvm>=15<16:../../lang/llvm

.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/terminfo.buildlink3.mk"
.include "../../textproc/rapidjson/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
