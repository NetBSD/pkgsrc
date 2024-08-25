# $NetBSD: Makefile,v 1.15 2024/08/25 10:11:22 wiz Exp $

DISTNAME=	libmaxminddb-1.11.0
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=maxmind/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://maxmind.github.io/libmaxminddb/
COMMENT=	C library for the MaxMind DB file format
LICENSE=	apache-2.0

GNU_CONFIGURE=		yes
USE_LANGUAGES+=		c
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
# cmake build doesn't install man pages yet
# https://github.com/maxmind/libmaxminddb/issues/351
#CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=ON

USE_CC_FEATURES=	c99

PKGCONFIG_OVERRIDE+=	src/libmaxminddb.pc.in

#.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
