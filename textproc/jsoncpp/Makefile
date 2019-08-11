# $NetBSD: Makefile,v 1.12 2019/08/11 17:53:27 adam Exp $

DISTNAME=	jsoncpp-1.9.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=open-source-parsers/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/open-source-parsers/jsoncpp
COMMENT=	JSON reader and writer in C++
LICENSE=	public-domain OR mit

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
CMAKE_ARGS+=		-DBUILD_SHARED_LIBS=ON
CMAKE_ARGS+=		-DJSONCPP_WITH_TESTS=OFF
PKGCONFIG_OVERRIDE=	pkg-config/jsoncpp.pc.in

.include "../../mk/bsd.pkg.mk"
