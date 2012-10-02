# $NetBSD: Makefile,v 1.17 2012/10/02 21:25:40 asau Exp $

MODNAME=		sqlite
CATEGORIES+=		databases
COMMENT=		PHP extension for SQLite 2.x databases

CONFLICTS=		php-sqlite-[0-9]*

PHP_VERSIONS_ACCEPTED=	53

.include "../../lang/php/phpversion.mk"

CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${BUILDLINK_PREFIX.sqlite}
CONFIGURE_ENV+=		PHP_PDO=no

.include "../../lang/php/ext.mk"
.include "../../databases/sqlite/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
