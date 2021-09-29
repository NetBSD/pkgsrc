# $NetBSD: Makefile,v 1.28 2021/09/29 19:00:17 adam Exp $

MODNAME=		zip
CATEGORIES+=		archivers
COMMENT=		PHP extension for ZIP archive handling
PKGREVISION=		6

CONFLICTS=		php-zip-[0-9]*

CONFIGURE_ARGS+=	--enable-zip
CONFIGURE_ARGS+=	--with-zlib-dir=${BUILDLINK_PREFIX.zlib}
CONFIGURE_ARGS+=	--with-libzip=${BUILDLINK_PREFIX.libzip}

USE_PHP_EXT_PATCHES=	yes

.include "../../lang/php/ext.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/libzip/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
