# $NetBSD: Makefile,v 1.43 2026/05/14 16:40:23 ryoon Exp $

MODNAME=		zip
PKGREVISION=		21
CATEGORIES+=		archivers
COMMENT=		PHP extension for ZIP archive handling

CONFLICTS=		php-zip-[0-9]* php${PHP_VER}-pecl-zip

CONFIGURE_ARGS+=	--enable-zip
CONFIGURE_ARGS+=	--with-zlib-dir=${BUILDLINK_PREFIX.zlib}
CONFIGURE_ARGS+=	--with-libzip=${BUILDLINK_PREFIX.libzip}

USE_PHP_EXT_PATCHES=	yes

.include "../../lang/php/ext.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/libzip/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
