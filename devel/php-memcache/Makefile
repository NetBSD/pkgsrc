# $NetBSD: Makefile,v 1.14 2016/09/11 17:03:25 taca Exp $
#

MODNAME=		memcache
PECL_VERSION=		2.2.7
PECL_LEGACY_VERSION_SCHEME=	yes
CATEGORIES+=		devel
COMMENT=		PHP extension for memcached

CONFLICTS=		php-memcache-[0-9]*

PHP_VERSIONS_ACCEPTED=	56

CONFIGURE_ARGS+=	--enable-${MODNAME}
CONFIGURE_ARGS+=	--with-zlib-dir=${BUILDLINK_PREFIX.zlib}
WRKSRC=			${WRKDIR}/${MODNAME}-${PECL_VERSION}

.include "../../lang/php/ext.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
