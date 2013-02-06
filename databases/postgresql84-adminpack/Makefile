# $NetBSD: Makefile,v 1.11 2013/02/06 23:21:56 jperkin Exp $

PKGNAME=	${DISTNAME:C/-/84-adminpack-/}
PKGREVISION=	2
COMMENT=	Admin pack module for pgAdmin management

DEPENDS+=	postgresql84-server>=${PKGVERSION_NOREV}:../../databases/postgresql84-server

.include "../../databases/postgresql84/Makefile.common"

BUILD_MAKE_FLAGS=	PGXS=1

BUILD_DIRS=		contrib/adminpack
REQD_DIRS+=		share/doc/postgresql/contrib
REQD_DIRS+=		share/postgresql/contrib

.include "../../databases/postgresql84-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
