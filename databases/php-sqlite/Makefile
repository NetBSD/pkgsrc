# $NetBSD: Makefile,v 1.4 2005/10/04 16:50:50 tv Exp $

MODNAME=		SQLite
PKGMODNAME=		sqlite
PKGNAME=		php-${PKGMODNAME}-${PHP_BASE_VERS}.${PECL_VERSION}
PKGREVISION=		3
PECL_VERSION=		1.0.3
CATEGORIES+=		databases
MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		PHP extension for SQLite 2.x databases

CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${BUILDLINK_PREFIX.sqlite}

.include "../../lang/php/ext.mk"
.include "../../databases/sqlite/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
