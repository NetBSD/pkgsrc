# $NetBSD: Makefile,v 1.3.2.1 2012/07/04 07:46:10 tron Exp $

PKGNAME=	${DISTNAME:C/-/90-replicationtools-/}
COMMENT=	PostgreSQL replication tools

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../databases/postgresql90/Makefile.common"

BUILD_DIRS+=		contrib/pg_archivecleanup
BUILD_DIRS+=		contrib/pg_standby

.include "../../databases/postgresql90-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
