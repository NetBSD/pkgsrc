# $NetBSD: Makefile,v 1.4 2020/09/05 11:25:39 ryoon Exp $

DISTNAME=	libnumbertext-1.0.6
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=Numbertext/}
EXTRACT_SUFX=	.tar.xz
GITHUB_PROJECT=	libnumbertext
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://numbertext.github.io/
COMMENT=	Convert to number names from numbers
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++11

GCC_REQD+=	5.0

CONFIGURE_ARGS+=	--disable-werror

PKGCONFIG_OVERRIDE+=	libnumbertext.pc.in

.include "../../mk/bsd.pkg.mk"
