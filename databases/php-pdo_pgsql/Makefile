# $NetBSD: Makefile,v 1.7 2008/03/13 17:38:48 joerg Exp $

PDO_DRIVER=		pgsql
PDO_COMMENT=		PostgreSQL
PDO_VERSION=		1.0.1
PKGREVISION=	1

.include "../../databases/php-pdo/module.mk"

CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${PGSQL_PREFIX}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../databases/php-pdo/buildlink3.mk"
