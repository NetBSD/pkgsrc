# $NetBSD: Makefile,v 1.2.2.1 2012/07/03 23:23:07 tron Exp $

PKGNAME=	${DISTNAME:C/-/91-adminpack-/}
COMMENT=	Admin pack module for pgAdmin management

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	postgresql91-server>=${PKGVERSION_NOREV}:../../databases/postgresql91-server

.include "../../databases/postgresql91/Makefile.common"

BUILD_MAKE_FLAGS=	PGXS=1

BUILD_DIRS=		contrib/adminpack

.include "../../databases/postgresql91-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
