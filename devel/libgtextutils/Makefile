# $NetBSD: Makefile,v 1.1 2022/04/05 18:41:20 bacon Exp $

DISTNAME=	libgtextutils-0.7.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=agordon/}
GITHUB_TAG=	510270ecf2e342a81d5dffbf38505bfe18d23dca

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/agordon/libgtextutils
COMMENT=	Gordon text utilities
LICENSE=	gnu-agpl-v3

USE_LANGUAGES=	c c++
USE_TOOLS+=	automake autoreconf pkg-config
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

PKGCONFIG_OVERRIDE=	gtextutils.pc.in

pre-configure:
	${RUN} cd ${WRKSRC} && autoreconf -fiv

.include "../../mk/bsd.pkg.mk"
