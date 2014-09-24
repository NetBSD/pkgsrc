# $NetBSD: Makefile,v 1.12 2014/09/24 21:32:32 jperkin Exp $
#

MODNAME=		memcache
PECL_VERSION=		2.2.7
PECL_LEGACY_VERSION_SCHEME=	yes
CATEGORIES+=		devel
COMMENT=		PHP extension for memcached

CONFLICTS=		php-memcache-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}
CONFIGURE_ARGS+=	--with-zlib-dir=${BUILDLINK_PREFIX.zlib}
WRKSRC=			${WRKDIR}/${MODNAME}-${PECL_VERSION}

.include "../../lang/php/ext.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
