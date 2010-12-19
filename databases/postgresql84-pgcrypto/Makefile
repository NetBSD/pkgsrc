# $NetBSD: Makefile,v 1.2 2010/12/19 09:53:42 adam Exp $

PKGNAME=	${DISTNAME:C/-/84-pgcrypto-/}
COMMENT=	Module providing cryptographic functions for PostgreSQL

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	postgresql84-server>=${PKGVERSION_NOREV}:../../databases/postgresql84-server

.include "../../databases/postgresql84/Makefile.common"

USE_LIBTOOL=		yes
PKG_LIBTOOL=		${PKG_SHLIBTOOL}

BUILD_DIRS=		contrib/pgcrypto
REQD_DIRS+=		${PG_SUBPREFIX}share/doc/postgresql/contrib
REQD_DIRS+=		${PG_SUBPREFIX}share/postgresql/contrib

.include "../../databases/postgresql84-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
