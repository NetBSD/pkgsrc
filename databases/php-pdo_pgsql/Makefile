# $NetBSD: Makefile,v 1.5 2006/12/28 12:12:58 joerg Exp $

PDO_DRIVER=		pgsql
PDO_COMMENT=		PostgreSQL
PDO_VERSION=		1.0.1
PKGREVISION=		1

.include "../../databases/php-pdo/module.mk"

CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${PGSQL_PREFIX}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../databases/php-pdo/buildlink3.mk"
