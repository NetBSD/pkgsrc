# $NetBSD: Makefile,v 1.7 2004/04/25 01:12:49 xtraeme Exp $

MODNAME=		odbc
CATEGORIES+=		databases
PKGREVISION=		# empty
COMMENT=		PHP4 extension for ODBC access

USE_BUILDLINK3=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-unixODBC=shared,${BUILDLINK_PREFIX.unixodbc}

.include "../../databases/unixodbc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
