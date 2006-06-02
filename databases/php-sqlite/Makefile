# $NetBSD: Makefile,v 1.7 2006/06/02 18:27:55 joerg Exp $

MODNAME=		SQLite
PKGMODNAME=		sqlite
PKGNAME=		${PHP_PKG_PREFIX}-${PKGMODNAME}-${PHP_BASE_VERS}.${PECL_VERSION}
PECL_VERSION=		1.0.3
CATEGORIES+=		databases
MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		PHP extension for SQLite 2.x databases

CONFLICTS=		php-sqlite-[0-9]*

CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${BUILDLINK_PREFIX.sqlite}

.include "../../lang/php/ext.mk"
.include "../../databases/sqlite/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
