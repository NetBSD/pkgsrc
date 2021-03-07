# $NetBSD: Makefile,v 1.15 2021/03/07 15:41:30 taca Exp $
#

MODNAME=		memcache
PECL_VERSION=		8.0
PECL_LEGACY_VERSION_SCHEME=	yes
CATEGORIES+=		devel

COMMENT=		PHP extension for memcached
LICENSE=		php

CONFLICTS=		php-memcache-[0-9]*

PHP_VERSIONS_ACCEPTED=	80

CONFIGURE_ARGS+=	--enable-${MODNAME}
CONFIGURE_ARGS+=	--with-zlib-dir=${BUILDLINK_PREFIX.zlib}
WRKSRC=			${WRKDIR}/${MODNAME}-${PECL_VERSION}

.include "../../lang/php/ext.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
