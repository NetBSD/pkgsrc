# $NetBSD: Makefile,v 1.12 2009/10/09 12:27:05 taca Exp $

MODNAME=		sqlite
PKGNAME=		${PHP_PKG_PREFIX}-${MODNAME}-${PHP_BASE_VERS}.1.0.3
CATEGORIES+=		databases
COMMENT=		PHP extension for SQLite 2.x databases

#
# Above PKGNAME definition should be removed after next release of lang/php5.
#

PHP_VERSIONS_ACCEPTED=	5

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=		php-sqlite-[0-9]*

CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${BUILDLINK_PREFIX.sqlite}
CONFIGURE_ENV+=		PHP_PDO=no

.include "../../lang/php/ext.mk"
.include "../../databases/sqlite/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
