# $NetBSD: Makefile,v 1.3 2025/02/08 03:41:14 taca Exp $
#

MODNAME=		memcache
PECL_VERSION=		4.0.5.2
PKGREVISION=		1
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
