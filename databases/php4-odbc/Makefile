# $NetBSD: Makefile,v 1.2 2001/12/03 08:31:00 jlam Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		odbc
CATEGORIES+=		databases
PKGREVISION=		# empty
COMMENT=		PHP4 extension for ODBC access

USE_BUILDLINK_ONLY=	YES
CONFIGURE_ARGS+=	--with-unixODBC=shared,${BUILDLINK_DIR}

.include "../../databases/unixodbc/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
