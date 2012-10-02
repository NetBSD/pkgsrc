# $NetBSD: Makefile,v 1.17 2012/10/02 21:25:40 asau Exp $

MODNAME=		pgsql
CATEGORIES+=		databases
COMMENT=		PHP extension for PostgreSQL databases

CONFLICTS=	php-pgsql-[0-9]*

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${PGSQL_PREFIX}

.include "../../lang/php/ext.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
