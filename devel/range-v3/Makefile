# $NetBSD: Makefile,v 1.2 2020/03/31 10:49:49 nia Exp $

DISTNAME=	range-v3-0.10.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ericniebler/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ericniebler/range-v3
COMMENT=	Range library for C++14/17/20, basis for std::ranges in C++20
LICENSE=	boost-license

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DRANGES_NATIVE=OFF
CMAKE_ARGS+=	-DRANGES_BUILD_CALENDAR_EXAMPLE=OFF

CMAKE_ARGS+=	-DRANGE_V3_DOCS=OFF
CMAKE_ARGS+=	-DRANGE_V3_EXAMPLES=OFF
CMAKE_ARGS+=	-DRANGE_V3_HEADER_CHECKS=OFF
CMAKE_ARGS+=	-DRANGE_V3_TESTS=OFF

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/include/module.modulemap

.include "../../mk/bsd.pkg.mk"
