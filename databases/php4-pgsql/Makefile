# $NetBSD: Makefile,v 1.6 2003/01/05 20:14:26 jlam Exp $

MODNAME=		pgsql
CATEGORIES+=		databases
PKGREVISION=		1
COMMENT=		PHP4 extension for PostgreSQL databases

USE_BUILDLINK2=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.postgresql-lib}

.include "../../databases/postgresql-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
