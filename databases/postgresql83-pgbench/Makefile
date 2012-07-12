# $NetBSD: Makefile,v 1.1.1.1 2012/07/12 18:12:02 asau Exp $

PKGNAME=	${DISTNAME:C/-/83-pgbench-/}
COMMENT=	PostgreSQL benchmarking tools

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../databases/postgresql83/Makefile.common"

#BUILD_MAKE_FLAGS=	PGXS=1

BUILD_DIRS+=		contrib/pgbench

.include "../../databases/postgresql83-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
