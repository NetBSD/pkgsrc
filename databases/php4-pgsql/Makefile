# $NetBSD: Makefile,v 1.2 2001/10/16 06:58:31 jlam Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		pgsql
CATEGORIES+=		databases
PHP_PKG_VERS=		# empty
COMMENT=		PHP4 extension for PostgreSQL databases

USE_BUILDLINK_ONLY=	YES
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../databases/postgresql-lib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
