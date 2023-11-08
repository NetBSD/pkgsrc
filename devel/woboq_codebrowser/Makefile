# $NetBSD: Makefile,v 1.20 2023/11/08 13:19:00 wiz Exp $

DISTNAME=	codebrowser-2.1.20230517
PKGNAME=	woboq_${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=KDAB/}
GITHUB_TAG=	caf31972d6a866f3c16cbde1960862bf9c0e16c1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://codebrowser.dev/
COMMENT=	Code analysis tool
LICENSE=	cc-by-nc-sa-v3.0-license

USE_CMAKE=	yes
USE_LANGUAGES=	c c++17
CMAKE_ARGS+=	-DLLVM_CONFIG_EXECUTABLE=${LLVM_CONFIG_PATH:Q}
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
# CMAKE_ARGS+=	-DCLANG_BUILTIN_HEADERS_DIR=${BUILDLINK_PREFIX.clang}/lib/clang/16/include
WRKSRC=		${WRKDIR}/codebrowser-${GITHUB_TAG}

USE_CXX_FEATURES+=	c++17

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--as-needed

.include "../../lang/clang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
