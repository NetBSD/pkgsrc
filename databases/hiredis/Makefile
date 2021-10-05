# $NetBSD: Makefile,v 1.8 2021/10/05 12:14:54 adam Exp $

DISTNAME=	hiredis-1.0.1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=redis/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	wiedi@frubar.net
HOMEPAGE=	https://github.com/redis/hiredis/
COMMENT=	Minimalistic C client library for the Redis database
LICENSE=	modified-bsd

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake
MAKE_ENV+=	DESTDIR=${DESTDIR}
TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
