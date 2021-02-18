# $NetBSD: Makefile,v 1.5 2021/02/18 10:20:30 wiz Exp $

DISTNAME=	libnumbertext-1.0.7
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=Numbertext/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://numbertext.github.io/
COMMENT=	Convert to number names from numbers
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++11

GCC_REQD+=	5

CONFIGURE_ARGS+=	--disable-werror

PKGCONFIG_OVERRIDE+=	libnumbertext.pc.in

.include "../../mk/bsd.pkg.mk"
