# $NetBSD: Makefile,v 1.1 2021/08/11 09:49:42 kardel Exp $

GITHUB_PROJECT=	libyang
GITHUB_TAG=	v2.0.7
DISTNAME=	v2.0.7
PKGNAME=	${GITHUB_PROJECT}2-${DISTNAME:S,^v,,}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=CESNET/}
DIST_SUBDIR=	${GITHUB_PROJECT}
CONFLICTS=	libyang-[0-9]*

MAINTAINER=	kardel@NetBSD.org
HOMEPAGE=	https://github.com/CESNET/libyang/
COMMENT=	YANG data modeling language library
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/libyang-2.0.7
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

TOOL_DEPENDS+=	cmocka>=1.1.5:../../devel/cmocka

PKGCONFIG_OVERRIDE+=	libyang.pc.in
PKGCONFIG_OVERRIDE+=	swig/libyang-cpp.pc.in

CMAKE_ARG_PATH=	..
CONFIGURE_DIRS=	_build

.include "../../mk/bsd.prefs.mk"

pre-configure:
	${MKDIR} ${WRKSRC}/_build

CMAKE_ARGS?=	-DCMAKE_BUILD_TYPE:String="Release"

.include "../../devel/pcre2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
