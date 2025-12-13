# $NetBSD: Makefile,v 1.5 2025/12/13 10:05:45 vins Exp $

DISTNAME=	asignify-20220101
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=vstakhov/}
GITHUB_PROJECT=	asignify
GITHUB_TAG=	d6b3651fa96f05aeefc318f75503fc9ca77b1f58

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://github.com/vstakhov/asignify
COMMENT=	Yet another signify tool
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake autoreconf

pre-configure:
	set -e; cd ${WRKSRC} && autoreconf -fiv

.include "../../mk/bsd.pkg.mk"
