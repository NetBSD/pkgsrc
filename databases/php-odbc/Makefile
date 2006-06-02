# $NetBSD: Makefile,v 1.7 2006/06/02 18:27:55 joerg Exp $

MODNAME=		odbc
CATEGORIES+=		databases
COMMENT=		PHP extension for ODBC access

CONFLICTS=	php-odbc-[0-9]

CONFIGURE_ARGS+=	--with-unixODBC=shared,${BUILDLINK_PREFIX.unixodbc}

.include "../../lang/php/ext.mk"
.include "../../databases/unixodbc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
