# $NetBSD: Makefile,v 1.14 2020/05/30 06:09:47 adam Exp $

DISTNAME=	jsoncpp-1.9.3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=open-source-parsers/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

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
