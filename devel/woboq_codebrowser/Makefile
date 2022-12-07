# $NetBSD: Makefile,v 1.16 2022/12/07 15:38:48 wiz Exp $

DISTNAME=	codebrowser-2.1.20221107
PKGNAME=	woboq_${DISTNAME}
CATEGORIES=	devel lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=KDAB/}
GITHUB_TAG=	e7bce1618726657d0615f0976f0db11a4f70f1f7

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://code.woboq.org/
COMMENT=	Code analysis tool
LICENSE=	cc-by-nc-sa-v3.0-license

USE_CMAKE=	yes
USE_LANGUAGES=	c c++11
CMAKE_ARGS+=	-DLLVM_CONFIG_EXECUTABLE=${LLVM_CONFIG_PATH:Q}
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
WRKSRC=		${WRKDIR}/codebrowser-${GITHUB_TAG}

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--as-needed

.include "../../lang/clang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
