# $NetBSD: Makefile,v 1.3 2021/09/09 07:39:15 kardel Exp $

GITHUB_PROJECT=	libyang
GITHUB_TAG=	v1.0.240
DISTNAME=	v1.0.240
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=CESNET/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	kardel@NetBSD.org
HOMEPAGE=	https://github.com/CESNET/libyang/
COMMENT=	YANG data modeling language library
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/libyang-1.0.240
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
CMAKE_ARGS+=	-DENABLE_LYD_PRIV=ON

.include "../../devel/pcre/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
