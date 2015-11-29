# $NetBSD: Makefile,v 1.4 2015/11/29 18:35:37 wiedi Exp $

DISTNAME=	hiredis-0.13.3
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=redis/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	wiedi@frubar.net
HOMEPAGE=	https://github.com/redis/hiredis/
COMMENT=	Minimalistic C client library for the Redis database
LICENSE=	modified-bsd

USE_TOOLS+=	gmake
USE_LIBTOOL=	yes
MAKE_ENV+=	DESTDIR=${DESTDIR}

.include "../../mk/bsd.pkg.mk"
