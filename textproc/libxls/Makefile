# $NetBSD: Makefile,v 1.3 2019/05/06 09:17:13 sjmulder Exp $

DISTNAME=	libxls-1.5.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=libxls/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	sjmulder@NetBSD.org
HOMEPAGE=	https://github.com/libxls/libxls
COMMENT=	Extract cell data from legacy Microsoft Excel files
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes
# cplusplus/* is used for tests, but built always
USE_LANGUAGES=	c c++11
USE_LIBTOOL=	yes

TEST_TARGET=	check

PKGCONFIG_OVERRIDE+=	libxls.pc.in

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
