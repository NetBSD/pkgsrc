# $NetBSD: Makefile,v 1.2 2012/07/16 13:34:49 asau Exp $

PKGNAME=	${DISTNAME:C/-/90-pgbench-/}
COMMENT=	PostgreSQL benchmarking tools

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../databases/postgresql90/Makefile.common"

BUILD_DIRS+=		contrib/pgbench

.include "../../databases/postgresql90-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
