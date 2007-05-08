# $NetBSD: Makefile,v 1.10 2007/05/08 11:30:50 adrianp Exp $

MODNAME=		pgsql
CATEGORIES+=		databases
COMMENT=		PHP extension for PostgreSQL databases

CONFLICTS=	php-pgsql-[0-9]*

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${PGSQL_PREFIX}

.include "../../lang/php/ext.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
