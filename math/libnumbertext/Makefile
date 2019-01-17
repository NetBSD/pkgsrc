# $NetBSD: Makefile,v 1.2 2019/01/17 15:56:05 khorben Exp $

DISTNAME=	libnumbertext-1.0.3
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=Numbertext/}
EXTRACT_SUFX=	.tar.xz
GITHUB_PROJECT=	libnumbertext
GITHUB_RELEASE=	1.0

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://numbertext.github.io/
COMMENT=	Convert to number names from numbers
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++11

GCC_REQD+=	5.0

PKGCONFIG_OVERRIDE+=	libnumbertext.pc.in

.include "../../mk/bsd.pkg.mk"
