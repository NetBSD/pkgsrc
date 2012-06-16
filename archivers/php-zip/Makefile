# $NetBSD: Makefile,v 1.14 2012/06/16 02:49:39 taca Exp $

MODNAME=		zip
PKGREVISION=		2
CATEGORIES+=		archivers
COMMENT=		PHP extension for ZIP archive handling

CONFLICTS=		php-zip-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--enable-zip
CONFIGURE_ARGS+=	--with-zlib-dir=${BUILDLINK_PREFIX.zlib}
USE_PHP_EXT_PATCHES=	yes

# Remove these PKGNAME tweak after PHP 5.2.18 release (after support of php52)
.include "../../lang/php/phpversion.mk"
.if ${PHP_BASE_VERS} == "5.2.17"
PKGNAME:=		${PHP_PKG_PREFIX}-${MODNAME}-${PHP_BASE_VERS}.1.8.11
.endif

.include "../../lang/php/ext.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
