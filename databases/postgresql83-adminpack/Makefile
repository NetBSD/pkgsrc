# $NetBSD: Makefile,v 1.1.1.1 2008/03/04 12:42:13 adam Exp $

PKGNAME=	postgresql83-adminpack-${BASE_VERS}
COMMENT=	Admin pack module for pgAdmin management

DEPENDS+=	postgresql83-server>=${BASE_VERS}:../../databases/postgresql83-server

.include "../../databases/postgresql83/Makefile.common"

BUILD_DIRS=		contrib/adminpack

USE_LIBTOOL=		yes
PKG_LIBTOOL=		${PKG_SHLIBTOOL}

REQD_DIRS+=		${PG_SUBPREFIX}share/doc/postgresql/contrib
REQD_DIRS+=		${PG_SUBPREFIX}share/postgresql/contrib

.include "../../databases/postgresql83-client/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
