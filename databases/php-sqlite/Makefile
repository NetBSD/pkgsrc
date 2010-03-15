# $NetBSD: Makefile,v 1.13 2010/03/15 16:45:59 taca Exp $

MODNAME=		sqlite
PKGNAME=		${PHP_PKG_PREFIX}-${MODNAME}-${PHP_BASE_VERS}.1.0.3
CATEGORIES+=		databases
COMMENT=		PHP extension for SQLite 2.x databases

#
# Above PKGNAME definition should be removed after next release of lang/php5.
#

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=		php-sqlite-[0-9]*

CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${BUILDLINK_PREFIX.sqlite}
CONFIGURE_ENV+=		PHP_PDO=no

.include "../../lang/php/ext.mk"
.include "../../databases/sqlite/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
