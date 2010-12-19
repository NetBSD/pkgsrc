# $NetBSD: Makefile,v 1.5 2010/12/19 09:53:53 adam Exp $

PKGNAME=	${DISTNAME:C/-/83-adminpack-/}
COMMENT=	Admin pack module for pgAdmin management

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	postgresql83-server>=${PKGVERSION_NOREV}:../../databases/postgresql83-server

.include "../../databases/postgresql83/Makefile.common"

USE_LIBTOOL=		yes
PKG_LIBTOOL=		${PKG_SHLIBTOOL}

BUILD_DIRS=		contrib/adminpack
REQD_DIRS+=		${PG_SUBPREFIX}share/doc/postgresql/contrib
REQD_DIRS+=		${PG_SUBPREFIX}share/postgresql/contrib

.include "../../databases/postgresql83-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
