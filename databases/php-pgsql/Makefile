# $NetBSD: Makefile,v 1.6 2006/02/05 23:08:34 joerg Exp $

MODNAME=		pgsql
PKGREVISION=		1
CATEGORIES+=		databases
COMMENT=		PHP extension for PostgreSQL databases


CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${PGSQL_PREFIX}

.include "../../lang/php/ext.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
