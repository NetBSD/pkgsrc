# $NetBSD: Makefile,v 1.4 2002/09/20 21:47:22 jlam Exp $

MODNAME=		odbc
CATEGORIES+=		databases
PKGREVISION=		# empty
COMMENT=		PHP4 extension for ODBC access

USE_BUILDLINK2=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-unixODBC=shared,${BUILDLINK_PREFIX.unixodbc}

.include "../../databases/unixodbc/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
