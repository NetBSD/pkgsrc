# $NetBSD: Makefile,v 1.1 2013/09/13 08:07:01 fhajny Exp $
#

MODNAME=		memcached
PECL_VERSION=		2.1.0
CATEGORIES+=		devel

MAINTAINER=		filip@joyent.com
HOMEPAGE=		http://github.com/andreiz/php-memcached
COMMENT=		PHP extension for interfacing with memcached via libmemcached library
LICENSE=		php

CONFLICTS=		php-memcached-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}
CONFIGURE_ARGS+=	--with-libmemcached-dir=${PREFIX}
#WRKSRC=			${WRKDIR}/${MODNAME}-${PECL_VERSION}

.include "../../lang/php/ext.mk"
.include "../../devel/libmemcached/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
