# $NetBSD: Makefile,v 1.6 2020/07/14 12:48:58 sjmulder Exp $

DISTNAME=	libxls-1.5.3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=libxls/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	sjmulder@NetBSD.org
HOMEPAGE=	https://github.com/libxls/libxls
COMMENT=	Extract cell data from legacy Microsoft Excel files
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

# C++ is only used for an optional test. Skip it rather than breaking
# the build on platforms with shoddy C++11 support.
#USE_LANGUAGES=	c c++11

TEST_TARGET=	check

PKGCONFIG_OVERRIDE+=	libxls.pc.in

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
