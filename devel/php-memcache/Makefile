# $NetBSD: Makefile,v 1.11 2012/10/31 11:19:23 asau Exp $
#

MODNAME=		memcache
PECL_VERSION=		2.2.7
PECL_LEGACY_VERSION_SCHEME=	yes
CATEGORIES+=		devel
COMMENT=		PHP extension for memcached

CONFLICTS=		php-memcache-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}
WRKSRC=			${WRKDIR}/${MODNAME}-${PECL_VERSION}

.include "../../lang/php/ext.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
