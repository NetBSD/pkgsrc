# $NetBSD: Makefile,v 1.1.1.1 2010/09/21 07:52:24 adam Exp $

PKGNAME=	postgresql90-pgcrypto-${BASE_VERS}
COMMENT=	Module providing cryptographic functions for PostgreSQL

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	postgresql90-server>=${BASE_VERS}:../../databases/postgresql90-server

.include "../../databases/postgresql90/Makefile.common"

BUILD_DIRS=		contrib/pgcrypto

USE_LIBTOOL=		yes
PKG_LIBTOOL=		${PKG_SHLIBTOOL}

REQD_DIRS+=		${PG_SUBPREFIX}share/doc/postgresql/contrib
REQD_DIRS+=		${PG_SUBPREFIX}share/postgresql/contrib

.include "../../databases/postgresql90-client/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
