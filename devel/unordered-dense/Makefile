# $NetBSD: Makefile,v 1.5 2026/09/26 14:48:33 ktnb Exp $

DISTNAME=	unordered_dense-5.1.0
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=martinus/}
GITHUB_PROJECT=	unordered_dense
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/martinus/unordered_dense/
COMMENT=	Fast and densely stored hashmap and hashset
LICENSE=	mit

WRKSRC=	${WRKDIR}/${DISTNAME}

USE_LANGUAGES=		c++
USE_CXX_FEATURES=	c++17

USE_TOOLS+=	cmake pkg-config

LDFLAGS.NetBSD+=	-lexecinfo

MESON_ARGS+=	-Dwerror=false

.include "../../devel/cmake/build.mk"
.include "../../devel/doctest/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../textproc/fmtlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
