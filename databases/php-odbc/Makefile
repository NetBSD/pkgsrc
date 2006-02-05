# $NetBSD: Makefile,v 1.6 2006/02/05 23:08:33 joerg Exp $

MODNAME=		odbc
PKGREVISION=		1
CATEGORIES+=		databases
COMMENT=		PHP extension for ODBC access


CONFIGURE_ARGS+=	--with-unixODBC=shared,${BUILDLINK_PREFIX.unixodbc}

.include "../../lang/php/ext.mk"
.include "../../databases/unixodbc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
