# $NetBSD: Makefile,v 1.1.1.1 2002/01/10 13:04:15 jlam Exp $

MODNAME=		pgsql
CATEGORIES+=		databases
PKGREVISION=		# empty
COMMENT=		PHP3 extension for PostgreSQL database access

USE_BUILDLINK_ONLY=	yes

.include "../../www/php3/Makefile.module"

CONFIGURE_ARGS+=	--with-pgsql=${BUILDLINK_DIR}
MOD_CPPFLAGS+=		-I${BUILDLINK_DIR}/include/pgsql
MOD_LIBS+=		-lpq -lcrypt

.include "../../databases/postgresql-lib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
