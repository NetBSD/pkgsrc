# $NetBSD: Makefile,v 1.1.1.1 2001/11/19 22:54:09 jlam Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		odbc
CATEGORIES+=		databases
PHP_PKG_VERS=		# empty
COMMENT=		PHP4 extension for ODBC access

USE_BUILDLINK_ONLY=	YES
CONFIGURE_ARGS+=	--with-unixODBC=shared,${BUILDLINK_DIR}

.include "../../databases/unixodbc/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
