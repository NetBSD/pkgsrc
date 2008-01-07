# $NetBSD: Makefile,v 1.3 2008/01/07 20:14:36 adam Exp $

PKGNAME=	postgresql82-tsearch2-${BASE_VERS}
COMMENT=	Tsearch2 contrib module for fulltext indexing in PostgreSQL

DEPENDS+=	postgresql82-server>=${BASE_VERS}:../../databases/postgresql82-server

.include "../../databases/postgresql82/Makefile.common"

BUILD_DIRS=		contrib/tsearch2/snowball contrib/tsearch2

USE_LIBTOOL=		yes
PKG_LIBTOOL=		${PKG_SHLIBTOOL}

REQD_DIRS+=		${PG_SUBPREFIX}share/doc/postgresql/contrib
REQD_DIRS+=		${PG_SUBPREFIX}share/postgresql/contrib

.include "../../databases/postgresql82-client/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
