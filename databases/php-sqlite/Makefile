# $NetBSD: Makefile,v 1.6 2006/03/04 21:29:10 jlam Exp $

MODNAME=		SQLite
PKGMODNAME=		sqlite
PKGNAME=		php-${PKGMODNAME}-${PHP_BASE_VERS}.${PECL_VERSION}
PKGREVISION=		4
PECL_VERSION=		1.0.3
CATEGORIES+=		databases
MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		PHP extension for SQLite 2.x databases

CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${BUILDLINK_PREFIX.sqlite}

.include "../../lang/php/ext.mk"
.include "../../databases/sqlite/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
