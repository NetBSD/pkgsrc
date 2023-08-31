# $NetBSD: Makefile,v 1.15 2023/08/31 10:09:02 wiz Exp $

DISTNAME=	QuantLib-1.12.1
PKGREVISION=	12
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_GITHUB:=lballabio/}
GITHUB_TAG=	${PKGBASE}-v${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://quantlib.org/
COMMENT=	C++ library for quantitative finance
LICENSE=	modified-bsd

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

USE_CXX_FEATURES+=	c++11

CXXFLAGS+=	-DBOOST_TIMER_ENABLE_DEPRECATED

TOOLS_DEPENDS.cmake=	cmake>=3.0:../../devel/cmake

SUBST_CLASSES+=		sover
SUBST_STAGE.sover=	pre-configure
SUBST_MESSAGE.sover=	Set the shared library version.
SUBST_FILES.sover=	CMakeLists.txt
SUBST_SED.sover=	-e 's,@PKGVERSION@,${PKGVERSION_NOREV},g'

.include "../../devel/boost-headers/buildlink3.mk"
BUILDLINK_DEPMETHOD.boost-libs=	build
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
