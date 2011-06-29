# $NetBSD: Makefile,v 1.2 2011/06/29 03:03:31 taca Exp $
#

MODNAME=	redis
PECL_VERSION=	2.1.3
PECL_DISTNAME=	nicolasff-phpredis-${PECL_VERSION}-0-g43bc590
CATEGORIES=	databases
MASTER_SITES=	http://download.github.com/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/nicolasff/phpredis
COMMENT=	PHP extension for Redis
LICENSE=	php

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/nicolasff-phpredis-43bc590

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
