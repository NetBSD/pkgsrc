# $NetBSD: Makefile,v 1.5 2019/11/26 12:43:42 wiz Exp $

DISTNAME=	hiredis-0.14.0
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
