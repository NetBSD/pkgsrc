# $NetBSD: Makefile,v 1.3 2002/02/28 06:17:13 jlam Exp $

MODNAME=		odbc
CATEGORIES+=		databases
PKGREVISION=		# empty
COMMENT=		PHP4 extension for ODBC access

USE_BUILDLINK_ONLY=	YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-unixODBC=shared,${BUILDLINK_DIR}

.include "../../databases/unixodbc/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
