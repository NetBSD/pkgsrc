# $NetBSD: Makefile,v 1.9 2019/04/09 06:48:18 wiz Exp $

DISTNAME=	jsoncpp-1.8.4
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=open-source-parsers/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/open-source-parsers/jsoncpp
COMMENT=	JSON reader and writer in C++
LICENSE=	public-domain OR mit

USE_CMAKE=		yes
CMAKE_ARGS+=		-DBUILD_SHARED_LIBS:BOOL=ON
CMAKE_ARGS+=		-DJSONCPP_WITH_TESTS:BOOL=OFF
USE_LANGUAGES=		c c++
PKGCONFIG_OVERRIDE=	pkg-config/jsoncpp.pc.in

.include "../../mk/bsd.pkg.mk"
