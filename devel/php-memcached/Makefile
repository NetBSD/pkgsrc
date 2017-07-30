# $NetBSD: Makefile,v 1.9 2017/07/30 22:32:15 wiz Exp $
#

MODNAME=		memcached
PECL_VERSION=		2.2.0
PKGREVISION=		1
CATEGORIES+=		devel

MAINTAINER=		filip@joyent.com
HOMEPAGE=		https://github.com/php-memcached-dev/php-memcached
COMMENT=		PHP extension for interfacing with memcached via libmemcached library
LICENSE=		php

CONFLICTS=		php-memcached-[0-9]*

PHP_VERSIONS_ACCEPTED=	56

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
