# $NetBSD: Makefile,v 1.6 2008/06/20 08:27:58 adam Exp $

PKGNAME=	postgresql81-tsearch2-${BASE_VERS}
COMMENT=	Tsearch2 contrib module for fulltext indexing in PostgreSQL

DEPENDS+=	postgresql81-server>=${BASE_VERS}:../../databases/postgresql81-server

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../databases/postgresql81/Makefile.common"

BUILD_DIRS=		contrib/tsearch2/snowball
BUILD_DIRS+=		contrib/tsearch2

USE_LIBTOOL=		yes
PKG_LIBTOOL=		${PKG_SHLIBTOOL}

.include "../../databases/postgresql81-client/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
