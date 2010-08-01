# $NetBSD: Makefile,v 1.1.1.1 2010/08/01 17:44:04 jdolecek Exp $

PKGNAME=	postgresql84-pgcrypto-${BASE_VERS}
COMMENT=	Module providing cryptographic functions for PostgreSQL

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	postgresql84-server>=${BASE_VERS}:../../databases/postgresql84-server

.include "../../databases/postgresql84/Makefile.common"

BUILD_DIRS=		contrib/pgcrypto

USE_LIBTOOL=		yes
PKG_LIBTOOL=		${PKG_SHLIBTOOL}

REQD_DIRS+=		${PG_SUBPREFIX}share/doc/postgresql/contrib
REQD_DIRS+=		${PG_SUBPREFIX}share/postgresql/contrib

.include "../../databases/postgresql84-client/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
