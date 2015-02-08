# $NetBSD: Makefile,v 1.8 2015/02/08 21:18:56 fhajny Exp $
#

MODNAME=	redis
PECL_VERSION=	2.2.5
PECL_LEGACY_VERSION_SCHEME=	yes
PECL_DISTNAME=	${PECL_VERSION}
CATEGORIES=	databases
MASTER_SITES=	https://github.com/nicolasff/phpredis/archive/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/nicolasff/phpredis
COMMENT=	PHP extension for Redis
LICENSE=	php

WRKSRC=		${WRKDIR}/phpredis-${PECL_VERSION}

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CFLAGS+=	-Wno-error=return-type
.endif

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
