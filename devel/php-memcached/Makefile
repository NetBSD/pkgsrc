# $NetBSD: Makefile,v 1.14 2026/01/08 14:17:47 taca Exp $
#

MODNAME=		memcached
PECL_VERSION=		3.3.0
CATEGORIES+=		devel

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/php-memcached-dev/php-memcached
COMMENT=		PHP extension for interfacing with memcached via libmemcached library
LICENSE=		php

CONFLICTS=		php-memcached-[0-9]*

PHP_VERSIONS_ACCEPTED=	74 82 83 84

USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++
CONFIGURE_ARGS+=	--enable-${MODNAME}
CONFIGURE_ARGS+=	--with-libmemcached-dir=${BUILDLINK_PREFIX.libmemcached}
CONFIGURE_ARGS+=	--with-zlib-dir=${BUILDLINK_PREFIX.zlib}

.include "options.mk"

.include "../../lang/php/ext.mk"
.include "../../devel/libmemcached/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
