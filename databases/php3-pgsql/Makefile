# $NetBSD: Makefile,v 1.3 2003/01/05 20:14:25 jlam Exp $

MODNAME=		pgsql
CATEGORIES+=		databases
PKGREVISION=		1
COMMENT=		PHP3 extension for PostgreSQL database access

USE_BUILDLINK2=		yes

.include "../../www/php3/Makefile.module"

CONFIGURE_ARGS+=	--with-pgsql=${BUILDLINK_PREFIX.postgresql-lib}
MOD_CPPFLAGS+=		-I${BUILDLINK_PREFIX.postgresql-lib}/include/postgresql
MOD_LIBS+=		-lpq -lcrypt

.include "../../databases/postgresql-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
