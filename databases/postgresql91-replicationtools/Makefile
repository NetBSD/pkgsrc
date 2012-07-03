# $NetBSD: Makefile,v 1.2.2.1 2012/07/03 23:23:08 tron Exp $

PKGNAME=	${DISTNAME:C/-/91-replicationtools-/}
COMMENT=	PostgreSQL replication tools

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../databases/postgresql91/Makefile.common"

BUILD_DIRS+=		contrib/pg_archivecleanup
BUILD_DIRS+=		contrib/pg_standby

.include "../../databases/postgresql91-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
