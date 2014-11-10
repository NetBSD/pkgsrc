# $NetBSD: Makefile,v 1.6 2014/11/10 20:28:32 rodent Exp $
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

WRKSRC=		${WRKDIR}/nicolasff-phpredis-43bc590

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CFLAGS+=	-Wno-error=return-type
.endif

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
