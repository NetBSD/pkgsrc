# $NetBSD: Makefile,v 1.4 2012/10/02 21:25:40 asau Exp $
#

MODNAME=	redis
PECL_VERSION=	2.1.3
PECL_LEGACY_VERSION_SCHEME=	yes
PECL_DISTNAME=	nicolasff-phpredis-${PECL_VERSION}-0-g43bc590
CATEGORIES=	databases
MASTER_SITES=	http://download.github.com/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/nicolasff/phpredis
COMMENT=	PHP extension for Redis
LICENSE=	php

WRKSRC=		${WRKDIR}/nicolasff-phpredis-43bc590

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
