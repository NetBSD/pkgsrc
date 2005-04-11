# $NetBSD: Makefile,v 1.4 2005/04/11 21:45:14 tv Exp $

MODNAME=		odbc
CATEGORIES+=		databases
PKGREVISION=		# empty
COMMENT=		PHP extension for ODBC access


CONFIGURE_ARGS+=	--with-unixODBC=shared,${BUILDLINK_PREFIX.unixodbc}

.include "../../lang/php/ext.mk"
.include "../../databases/unixodbc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
