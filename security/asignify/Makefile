# $NetBSD: Makefile,v 1.3 2017/07/30 22:32:21 wiz Exp $

DISTNAME=	asignify-20150220
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=vstakhov/}
GITHUB_PROJECT=	asignify
GITHUB_TAG=	746b6dfc1f8d6deb320b6679f00b78061f4f08e6

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://github.com/vstakhov/asignify
COMMENT=	Yet another signify tool
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	automake

pre-configure:
		cd ${WRKSRC}; sh ./autogen.sh

.include "../../mk/bsd.pkg.mk"
