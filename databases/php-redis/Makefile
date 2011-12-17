# $NetBSD: Makefile,v 1.3 2011/12/17 13:46:27 obache Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/nicolasff-phpredis-43bc590

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
