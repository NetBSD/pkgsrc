# $NetBSD: Makefile,v 1.4 2025/05/18 01:04:32 ryoon Exp $

DISTNAME=	frozen-1.2.0
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
