# $NetBSD: Makefile,v 1.1.1.1 2012/07/12 16:29:33 asau Exp $

PKGNAME=	${DISTNAME:C/-/90-pgbench-/}
COMMENT=	PostgreSQL benchmarking tools

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../databases/postgresql90/Makefile.common"

BUILD_MAKE_FLAGS=	PGXS=1

BUILD_DIRS+=		contrib/pgbench

.include "../../databases/postgresql90-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
