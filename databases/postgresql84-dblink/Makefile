# $NetBSD: Makefile,v 1.2 2010/12/19 09:53:42 adam Exp $

PKGNAME=	${DISTNAME:C/-/84-dblink-/}
COMMENT=	dblink module for remote database connections

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	postgresql84-server>=${PKGVERSION_NOREV}:../../databases/postgresql84-server

.include "../../databases/postgresql84/Makefile.common"

USE_LIBTOOL=		yes
PKG_LIBTOOL=		${PKG_SHLIBTOOL}

BUILD_DIRS=		src/interfaces/libpq
BUILD_DIRS+=		contrib/dblink
INSTALL_DIRS=		contrib/dblink
REQD_DIRS+=		${PG_SUBPREFIX}share/doc/postgresql/contrib
REQD_DIRS+=		${PG_SUBPREFIX}share/postgresql/contrib

.include "../../databases/postgresql84-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
