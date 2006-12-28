# $NetBSD: Makefile,v 1.9 2006/12/28 12:12:58 joerg Exp $

MODNAME=		pgsql
PKGREVISION=		1
CATEGORIES+=		databases
COMMENT=		PHP extension for PostgreSQL databases

CONFLICTS=	php-pgsql-[0-9]*

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${PGSQL_PREFIX}

.include "../../lang/php/ext.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
