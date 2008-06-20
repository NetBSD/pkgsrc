# $NetBSD: Makefile,v 1.8 2008/06/20 01:09:11 joerg Exp $

MODNAME=		SQLite
PKGMODNAME=		sqlite
PKGNAME=		${PHP_PKG_PREFIX}-${PKGMODNAME}-${PHP_BASE_VERS}.${PECL_VERSION}
PECL_VERSION=		1.0.3
CATEGORIES+=		databases
MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		PHP extension for SQLite 2.x databases

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=		php-sqlite-[0-9]*

CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${BUILDLINK_PREFIX.sqlite}

.include "../../lang/php/ext.mk"
.include "../../databases/sqlite/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
