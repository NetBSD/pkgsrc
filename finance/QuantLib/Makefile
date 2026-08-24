# $NetBSD: Makefile,v 1.23 2026/08/24 08:42:17 adam Exp $

DISTNAME=	QuantLib-1.40
PKGREVISION=	2
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_GITHUB:=lballabio/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://quantlib.org/
COMMENT=	C++ library for quantitative finance
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++

USE_CXX_FEATURES+=	c++11

CXXFLAGS+=	-DBOOST_TIMER_ENABLE_DEPRECATED

.include "../../devel/cmake/build.mk"
.include "../../devel/boost-headers/buildlink3.mk"
BUILDLINK_DEPMETHOD.boost-libs=	build
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
