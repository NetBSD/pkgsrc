# $NetBSD: Makefile,v 1.3 2024/08/25 06:18:34 wiz Exp $

DISTNAME=	frozen-1.1.1
CATEGORIES=	devel
MASTER_SITES=	https://dev-www.libreoffice.org/src/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/serge-sans-paille/frozen
COMMENT=	Header-only, constexpr alternative to gperf for C++14 users
LICENSE=	apache-2.0

USE_LANGUAGES=	c++

# constexpr tests fail with at least GCC 12 and 13
CMAKE_CONFIGURE_ARGS+=	-DBUILD_TESTING=OFF

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
