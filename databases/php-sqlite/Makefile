# $NetBSD: Makefile,v 1.14 2012/06/16 02:54:11 taca Exp $

MODNAME=		sqlite
CATEGORIES+=		databases
COMMENT=		PHP extension for SQLite 2.x databases

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=		php-sqlite-[0-9]*

PHP_VERSIONS_ACCEPTED=	52 53

.include "../../lang/php/phpversion.mk"

# Remove these PKGNAME tweak after PHP 5.2.18 (or end of supporting php52)
# *AND* after PHP 5.3.14 release
.if ${PHP_BASE_VERS} == "5.2.17" || ${PHP_BASE_VERS} == "5.3.14"
PKGNAME=		${PHP_PKG_PREFIX}-${MODNAME}-${PHP_BASE_VERS}.1.0.3
.endif

CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${BUILDLINK_PREFIX.sqlite}
CONFIGURE_ENV+=		PHP_PDO=no

.include "../../lang/php/ext.mk"
.include "../../databases/sqlite/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
