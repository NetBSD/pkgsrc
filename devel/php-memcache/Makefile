# $NetBSD: Makefile,v 1.3 2006/06/04 16:26:53 joerg Exp $
#

MODNAME=		memcache
PECL_VERSION=		2.0.1
CATEGORIES+=		devel
COMMENT=		PHP extension for memcached

CONFLICTS=	php-memcache-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}
WRKSRC=			${WRKDIR}/${MODNAME}-${PECL_VERSION}

.include "../../lang/php/ext.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
