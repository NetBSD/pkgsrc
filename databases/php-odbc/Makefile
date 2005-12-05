# $NetBSD: Makefile,v 1.5 2005/12/05 20:49:58 rillig Exp $

MODNAME=		odbc
CATEGORIES+=		databases
COMMENT=		PHP extension for ODBC access


CONFIGURE_ARGS+=	--with-unixODBC=shared,${BUILDLINK_PREFIX.unixodbc}

.include "../../lang/php/ext.mk"
.include "../../databases/unixodbc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
