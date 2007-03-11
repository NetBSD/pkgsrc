# $NetBSD: Makefile,v 1.4 2007/03/11 16:28:38 grant Exp $
#

MODNAME=		memcache
PECL_VERSION=		2.1.0
CATEGORIES+=		devel
COMMENT=		PHP extension for memcached

CONFLICTS=		php-memcache-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}
WRKSRC=			${WRKDIR}/${MODNAME}-${PECL_VERSION}

.include "options.mk"

.include "../../lang/php/ext.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
