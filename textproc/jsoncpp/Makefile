# $NetBSD: Makefile,v 1.16 2021/11/03 20:52:23 adam Exp $

DISTNAME=	jsoncpp-1.9.5
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=open-source-parsers/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/open-source-parsers/jsoncpp
COMMENT=	JSON reader and writer in C++
LICENSE=	public-domain OR mit

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
CMAKE_ARGS+=		-DBUILD_STATIC_LIBS=OFF
CMAKE_ARGS+=		-DBUILD_OBJECT_LIBS=OFF
CMAKE_ARGS+=		-DJSONCPP_WITH_TESTS=OFF
PKGCONFIG_OVERRIDE=	pkg-config/jsoncpp.pc.in
CONFIGURE_DIRS=		${WRKDIR}/build
CMAKE_ARG_PATH=		${WRKSRC}

post-extract:
	${MKDIR} ${WRKDIR}/build

.include "../../mk/bsd.pkg.mk"
