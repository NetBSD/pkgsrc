# $NetBSD: Makefile,v 1.3 2010/01/17 12:02:11 wiz Exp $

PKGNAME=	postgresql83-adminpack-${BASE_VERS}
PKGREVISION=	1
COMMENT=	Admin pack module for pgAdmin management

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	postgresql83-server>=${BASE_VERS}:../../databases/postgresql83-server

.include "../../databases/postgresql83/Makefile.common"

BUILD_DIRS=		contrib/adminpack

USE_LIBTOOL=		yes
PKG_LIBTOOL=		${PKG_SHLIBTOOL}

REQD_DIRS+=		${PG_SUBPREFIX}share/doc/postgresql/contrib
REQD_DIRS+=		${PG_SUBPREFIX}share/postgresql/contrib

.include "../../databases/postgresql83-client/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
