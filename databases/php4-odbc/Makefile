# $NetBSD: Makefile,v 1.5 2003/05/02 11:54:14 wiz Exp $

MODNAME=		odbc
CATEGORIES+=		databases
PKGREVISION=		1
COMMENT=		PHP4 extension for ODBC access

USE_BUILDLINK2=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-unixODBC=shared,${BUILDLINK_PREFIX.unixodbc}

.include "../../databases/unixodbc/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
