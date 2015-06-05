# $NetBSD: Makefile,v 1.2 2015/06/05 14:07:27 wiedi Exp $

DISTNAME=	hiredis-0.13.1
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
