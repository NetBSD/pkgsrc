# $NetBSD: Makefile,v 1.9 2006/10/20 21:53:33 jdolecek Exp $

MODNAME=		odbc
CATEGORIES+=		databases
COMMENT=		PHP extension for ODBC access

CONFLICTS=	php-odbc-[0-9]*

CONFIGURE_ARGS+=	--with-unixODBC=shared,${BUILDLINK_PREFIX.unixodbc}

BROKEN=		module kills Apache1 or CLI PHP on startup due to threaded unixodbc

.include "../../lang/php/ext.mk"
.include "../../databases/unixodbc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
