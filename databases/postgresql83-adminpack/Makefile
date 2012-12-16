# $NetBSD: Makefile,v 1.12 2012/12/16 01:52:03 obache Exp $

PKGNAME=	${DISTNAME:C/-/83-adminpack-/}
PKGREVISION=	1
COMMENT=	Admin pack module for pgAdmin management

DEPENDS+=	postgresql83-server>=${PKGVERSION_NOREV}:../../databases/postgresql83-server

.include "../../databases/postgresql83/Makefile.common"

BUILD_DIRS=		contrib/adminpack
BUILD_MAKE_FLAGS=	PGXS=1
REQD_DIRS+=		share/doc/postgresql/contrib
REQD_DIRS+=		share/postgresql/contrib

.include "../../databases/postgresql83-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
