# $NetBSD: Makefile,v 1.11 2004/07/24 22:45:15 recht Exp $

MODNAME=		pgsql
PKGREVISION=		# empty
CATEGORIES+=		databases
COMMENT=		PHP4 extension for PostgreSQL databases

USE_BUILDLINK3=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${PGSQL_PREFIX}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
