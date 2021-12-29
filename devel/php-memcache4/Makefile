# $NetBSD: Makefile,v 1.2 2021/12/29 06:05:18 taca Exp $
#

MODNAME=		memcache
PECL_VERSION=		4.0.5.2
CATEGORIES+=		devel

COMMENT=		PHP extension for memcached
LICENSE=		php

CONFLICTS=		php-memcache-[0-9]*

PHP_VERSIONS_ACCEPTED=	74

CONFIGURE_ARGS+=	--enable-${MODNAME}
CONFIGURE_ARGS+=	--with-zlib-dir=${BUILDLINK_PREFIX.zlib}
WRKSRC=			${WRKDIR}/${MODNAME}-${PECL_VERSION}

.include "../../lang/php/ext.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
