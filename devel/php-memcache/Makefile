# $NetBSD: Makefile,v 1.9 2011/12/17 13:46:27 obache Exp $
#

MODNAME=		memcache
PECL_VERSION=		2.2.6
PECL_LEGACY_VERSION_SCHEME=	yes
CATEGORIES+=		devel
COMMENT=		PHP extension for memcached

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=		php-memcache-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}
WRKSRC=			${WRKDIR}/${MODNAME}-${PECL_VERSION}

.include "../../lang/php/ext.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
