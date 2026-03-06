# $NetBSD: Makefile,v 1.18 2026/03/06 06:21:35 adam Exp $

DISTNAME=	libmaxminddb-1.13.3
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=maxmind/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://maxmind.github.io/libmaxminddb/
COMMENT=	C library for the MaxMind DB file format
LICENSE=	apache-2.0

USE_CC_FEATURES=	c99
USE_LANGUAGES=		c
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	src/libmaxminddb.pc.in
TEST_TARGET=		check
# cmake build doesn't install man pages yet
# https://github.com/maxmind/libmaxminddb/issues/351
#CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=ON

#.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
