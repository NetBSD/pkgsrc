# $NetBSD: Makefile,v 1.1 2014/04/02 17:25:44 wiedi Exp $

VERSION=	0.11.0
DISTNAME=	v${VERSION}
PKGNAME=	hiredis-${VERSION}
CATEGORIES=	databases
MASTER_SITES=	https://github.com/redis/hiredis/archive/

MAINTAINER=	wiedi@frubar.net
HOMEPAGE=	https://github.com/redis/hiredis/
COMMENT=	Minimalistic C client library for the Redis database
LICENSE=	modified-bsd

USE_TOOLS+=	gmake
USE_LIBTOOL=	yes
WRKSRC=		${WRKDIR}/hiredis-${VERSION}
MAKE_ENV+=	DESTDIR=${DESTDIR}

.include "../../mk/bsd.pkg.mk"
