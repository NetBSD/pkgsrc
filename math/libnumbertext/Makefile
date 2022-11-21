# $NetBSD: Makefile,v 1.9 2022/11/21 21:01:31 adam Exp $

DISTNAME=	libnumbertext-1.0.11
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=Numbertext/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://numbertext.github.io/
COMMENT=	Convert to number names from numbers
LICENSE=	modified-bsd

USE_LANGUAGES=		c c++11
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-werror
PKGCONFIG_OVERRIDE+=	libnumbertext.pc.in
TEST_TARGET=		check
REPLACE_SH=		tests/test.sh

GCC_REQD+=	5

.include "../../mk/bsd.pkg.mk"
