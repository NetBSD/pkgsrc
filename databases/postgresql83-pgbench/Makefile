# $NetBSD: Makefile,v 1.2 2012/07/16 13:34:49 asau Exp $

PKGNAME=	${DISTNAME:C/-/83-pgbench-/}
COMMENT=	PostgreSQL benchmarking tools

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../databases/postgresql83/Makefile.common"

BUILD_DIRS+=		contrib/pgbench

.include "../../databases/postgresql83-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
