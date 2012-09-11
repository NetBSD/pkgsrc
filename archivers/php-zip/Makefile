# $NetBSD: Makefile,v 1.16 2012/09/11 19:46:59 asau Exp $

MODNAME=		zip
CATEGORIES+=		archivers
COMMENT=		PHP extension for ZIP archive handling

CONFLICTS=		php-zip-[0-9]*

CONFIGURE_ARGS+=	--enable-zip
CONFIGURE_ARGS+=	--with-zlib-dir=${BUILDLINK_PREFIX.zlib}
USE_PHP_EXT_PATCHES=	yes

.include "../../lang/php/ext.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
