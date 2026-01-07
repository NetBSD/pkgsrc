# $NetBSD: Makefile,v 1.32 2026/01/07 08:46:47 wiz Exp $

DISTNAME=	codebrowser-2.1.20250221
PKGNAME=	woboq_${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=KDAB/}
GITHUB_TAG=	9c819d5072dba9ba8eb07646d712b46229f7ecb5

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://codebrowser.dev/
COMMENT=	Code analysis tool
LICENSE=	cc-by-nc-sa-v3.0-license

USE_CXX_FEATURES=	c++17
USE_LANGUAGES=		c c++

CMAKE_CONFIGURE_ARGS+=	-DLLVM_CONFIG_EXECUTABLE=${LLVM_CONFIG_PATH:Q}
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release

WRKSRC=		${WRKDIR}/codebrowser-${GITHUB_TAG}

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--as-needed

.include "../../devel/cmake/build.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
