# $NetBSD: Makefile,v 1.9 2004/04/25 01:12:49 xtraeme Exp $

MODNAME=		pgsql
PKGREVISION=		1
CATEGORIES+=		databases
COMMENT=		PHP4 extension for PostgreSQL databases

USE_BUILDLINK3=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.postgresql-lib}

.include "../../databases/postgresql-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
