# $NetBSD: Makefile,v 1.7 2010/03/08 12:13:07 fhajny Exp $
#

MODNAME=		memcache
PECL_VERSION=		2.2.5
CATEGORIES+=		devel
COMMENT=		PHP extension for memcached

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=		php-memcache-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}
WRKSRC=			${WRKDIR}/${MODNAME}-${PECL_VERSION}

.include "../../lang/php/ext.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
