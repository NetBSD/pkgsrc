# $NetBSD: Makefile,v 1.4 2008/01/18 05:06:30 tnn Exp $

PKGNAME=	postgresql82-adminpack-${BASE_VERS}
PKGREVISION=	1
COMMENT=	Admin pack module for pgAdmin management

DEPENDS+=	postgresql82-server>=${BASE_VERS}:../../databases/postgresql82-server

.include "../../databases/postgresql82/Makefile.common"

BUILD_DIRS=		contrib/adminpack

USE_LIBTOOL=		yes
PKG_LIBTOOL=		${PKG_SHLIBTOOL}

REQD_DIRS+=		${PG_SUBPREFIX}share/doc/postgresql/contrib
REQD_DIRS+=		${PG_SUBPREFIX}share/postgresql/contrib

.include "../../databases/postgresql82-client/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
