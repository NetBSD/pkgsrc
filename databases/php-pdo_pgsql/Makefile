# $NetBSD: Makefile,v 1.9 2009/03/05 20:58:37 joerg Exp $

PDO_DRIVER=		pgsql
PDO_COMMENT=		PostgreSQL
PDO_VERSION=		1.0.1
PKGREVISION=	1

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../databases/php-pdo/module.mk"

CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${PGSQL_PREFIX}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../databases/php-pdo/buildlink3.mk"

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
