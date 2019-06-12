# $NetBSD: Makefile,v 1.4 2019/06/12 21:09:59 sjmulder Exp $

DISTNAME=	libxls-1.5.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=libxls/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	sjmulder@NetBSD.org
HOMEPAGE=	https://github.com/libxls/libxls
COMMENT=	Extract cell data from legacy Microsoft Excel files
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes
# C++11 support needed only for a test, see:
# https://github.com/libxls/libxls/pull/61
USE_LANGUAGES=	c c++11
USE_LIBTOOL=	yes
# workaround for failed builds until above PR is merged
GCC_REQD+=	4.8

TEST_TARGET=	check

PKGCONFIG_OVERRIDE+=	libxls.pc.in

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
