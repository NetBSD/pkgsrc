# $NetBSD: Makefile,v 1.9 2005/12/05 23:55:04 rillig Exp $

.include "Makefile.common"

PKGNAME=		odbc-postgresql-${BASE_VERS}
COMMENT=		ODBC interface to PostgreSQL

CONFIGURE_ARGS+=	--with-odbcinst=${PKG_SYSCONFDIR:Q}

.include "../../mk/bsd.pkg.mk"
