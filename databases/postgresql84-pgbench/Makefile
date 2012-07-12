# $NetBSD: Makefile,v 1.1.1.1 2012/07/12 17:18:42 asau Exp $

PKGNAME=	${DISTNAME:C/-/84-pgbench-/}
COMMENT=	PostgreSQL benchmarking tools

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../databases/postgresql84/Makefile.common"

#BUILD_MAKE_FLAGS=	PGXS=1

BUILD_DIRS+=		contrib/pgbench

.include "../../databases/postgresql84-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
