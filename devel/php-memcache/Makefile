# $NetBSD: Makefile,v 1.19 2025/02/22 17:05:57 taca Exp $
#

MODNAME=		memcache
PECL_VERSION=		8.2
PECL_LEGACY_VERSION_SCHEME=	yes
CATEGORIES+=		devel

COMMENT=		PHP extension for memcached
LICENSE=		php

CONFLICTS=		php-memcache-[0-9]*

PHP_VERSIONS_ACCEPTED=	81 82 83 84

CONFIGURE_ARGS+=	--enable-${MODNAME}
CONFIGURE_ARGS+=	--with-zlib-dir=${BUILDLINK_PREFIX.zlib}
WRKSRC=			${WRKDIR}/${MODNAME}-${PECL_VERSION}

.include "../../lang/php/ext.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
