# $NetBSD: Makefile,v 1.1 2026/09/12 16:49:53 drixter Exp $

DISTNAME=	bgpq4-1.16
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=bgp/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	https://github.com/bgp/bgpq4/
COMMENT=	BGP filtering automation tool
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake autoconf automake

pre-configure:
	${RUN} cd ${WRKSRC} && autoreconf -fiv

.include "../../mk/bsd.pkg.mk"
