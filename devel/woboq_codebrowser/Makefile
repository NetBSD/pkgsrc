# $NetBSD: Makefile,v 1.15 2022/11/23 16:19:54 adam Exp $

DISTNAME=	codebrowser-2.1.20220614
PKGNAME=	woboq_${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=KDAB/}
GITHUB_TAG=	ff3846d2addc75d1077435a3df87fd7606e54485

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
