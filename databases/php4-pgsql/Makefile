# $NetBSD: Makefile,v 1.10 2004/07/06 19:52:01 jdolecek Exp $

MODNAME=		pgsql
PKGREVISION=		# empty
CATEGORIES+=		databases
COMMENT=		PHP4 extension for PostgreSQL databases

USE_BUILDLINK3=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.postgresql-lib}

.include "../../databases/postgresql-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
