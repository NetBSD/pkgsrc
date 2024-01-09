# $NetBSD: Makefile,v 1.2 2024/01/09 15:53:59 chopps Exp $

GITHUB_PROJECT=	libyang
GITHUB_TAG=	v2.1.128
DISTNAME=	v2.1.128
PKGNAME=	${GITHUB_PROJECT}2-${DISTNAME:S,^v,,}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=CESNET/}
DIST_SUBDIR=	${GITHUB_PROJECT}
CONFLICTS=	libyang-[0-9]*

MAINTAINER=	kardel@NetBSD.org
HOMEPAGE=	https://github.com/CESNET/libyang/
COMMENT=	YANG data modeling language library
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/libyang-2.1.128
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

TOOL_DEPENDS+=	cmocka>=1.1.5:../../devel/cmocka

PKGCONFIG_OVERRIDE+=	libyang.pc.in
PKGCONFIG_OVERRIDE+=	swig/libyang-cpp.pc.in

.include "../../mk/bsd.prefs.mk"

CMAKE_ARGS?=	-DENABLE_TESTS=ON -DCMAKE_BUILD_TYPE:String="Release"
TEST_TARGET?=	test

.include "../../devel/cmocka/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
