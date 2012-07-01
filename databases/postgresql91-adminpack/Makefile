# $NetBSD: Makefile,v 1.3 2012/07/01 19:49:24 morr Exp $

PKGNAME=	${DISTNAME:C/-/91-adminpack-/}
COMMENT=	Admin pack module for pgAdmin management

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	postgresql91-server>=${PKGVERSION_NOREV}:../../databases/postgresql91-server

.include "../../databases/postgresql91/Makefile.common"

BUILD_MAKE_FLAGS=	PGXS=1

BUILD_DIRS=		contrib/adminpack

.include "../../databases/postgresql91-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
