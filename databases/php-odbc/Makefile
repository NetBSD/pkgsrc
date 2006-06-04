# $NetBSD: Makefile,v 1.8 2006/06/04 16:26:53 joerg Exp $

MODNAME=		odbc
CATEGORIES+=		databases
COMMENT=		PHP extension for ODBC access

CONFLICTS=	php-odbc-[0-9]*

CONFIGURE_ARGS+=	--with-unixODBC=shared,${BUILDLINK_PREFIX.unixodbc}

.include "../../lang/php/ext.mk"
.include "../../databases/unixodbc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
