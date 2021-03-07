# $NetBSD: Makefile,v 1.1 2021/03/07 15:36:43 taca Exp $
#

MODNAME=		memcache
PECL_VERSION=		2.2.7
PECL_LEGACY_VERSION_SCHEME=	yes
CATEGORIES+=		devel

COMMENT=		PHP extension for memcached
LICENSE=		php

CONFLICTS=		php-memcache-[0-9]*

PHP_VERSIONS_ACCEPTED=	56

CONFIGURE_ARGS+=	--enable-${MODNAME}
CONFIGURE_ARGS+=	--with-zlib-dir=${BUILDLINK_PREFIX.zlib}
WRKSRC=			${WRKDIR}/${MODNAME}-${PECL_VERSION}

.include "../../lang/php/ext.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
