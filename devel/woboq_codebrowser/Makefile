# $NetBSD: Makefile,v 1.24 2024/11/01 00:51:35 wiz Exp $

DISTNAME=	codebrowser-2.1.20231117
PKGNAME=	woboq_${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=KDAB/}
GITHUB_TAG=	1808e96d4c62417952389d536576d53bb6da4053

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://codebrowser.dev/
COMMENT=	Code analysis tool
LICENSE=	cc-by-nc-sa-v3.0-license

USE_CXX_FEATURES=	c++17
USE_LANGUAGES=		c c++

CMAKE_CONFIGURE_ARGS+=	-DLLVM_CONFIG_EXECUTABLE=${LLVM_CONFIG_PATH:Q}
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
#CMAKE_CONFIGURE_ARGS+=	-DCLANG_BUILTIN_HEADERS_DIR=${BUILDLINK_PREFIX.clang}/lib/clang/17/include
WRKSRC=		${WRKDIR}/codebrowser-${GITHUB_TAG}

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--as-needed

.include "../../devel/cmake/build.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
