# $NetBSD: Makefile,v 1.12 2011/02/21 16:30:44 taca Exp $

MODNAME=		zip
PKGREVISION=		1
CATEGORIES+=		archivers
COMMENT=		PHP extension for ZIP archive handling

CONFLICTS=		php-zip-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--enable-zip
CONFIGURE_ARGS+=	--with-zlib-dir=${BUILDLINK_PREFIX.zlib}

# Remove these PKGNAME tweak after PHP 5.2.14 release
.include "../../lang/php/phpversion.mk"
.if ${PKG_PHP_VERSION} == "5"
PKGNAME:=		${PHP_PKG_PREFIX}-${MODNAME}-${PHP_BASE_VERS}.1.8.11
.endif

.include "../../lang/php/ext.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
