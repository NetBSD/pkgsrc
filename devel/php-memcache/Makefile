# $NetBSD: Makefile,v 1.1.1.1 2006/04/20 11:30:47 grant Exp $
#

MODNAME=		memcache
PECL_VERSION=		2.0.1
CATEGORIES+=		devel
COMMENT=		PHP extension for memcached

CONFIGURE_ARGS+=	--enable-${MODNAME}
WRKSRC=			${WRKDIR}/${MODNAME}-${PECL_VERSION}

.include "../../lang/php/ext.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
