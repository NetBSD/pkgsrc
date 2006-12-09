# $NetBSD: Makefile,v 1.1.1.1 2006/12/09 16:13:57 adam Exp $

PKGNAME=	postgresql82-tsearch2-${BASE_VERS}
COMMENT=	Tsearch2 contrib module for fulltext indexing in PostgreSQL

DEPENDS+=	postgresql82-server>=${BASE_VERS}:../../databases/postgresql82-server

.include "../../databases/postgresql82/Makefile.common"

BUILD_DIRS=		contrib/tsearch2/snowball contrib/tsearch2

USE_LIBTOOL=		yes
PKG_LIBTOOL=		${PKG_SHLIBTOOL}

.include "../../databases/postgresql82-client/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
