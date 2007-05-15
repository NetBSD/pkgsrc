# $NetBSD: Makefile,v 1.9.4.1 2007/05/15 23:44:30 salo Exp $

MODNAME=		pgsql
CATEGORIES+=		databases
COMMENT=		PHP extension for PostgreSQL databases

CONFLICTS=	php-pgsql-[0-9]*

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${PGSQL_PREFIX}

.include "../../lang/php/ext.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
