# $NetBSD: Makefile,v 1.6 2020/03/22 18:20:11 wiz Exp $

DISTNAME=	hiredis-0.14.1
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
