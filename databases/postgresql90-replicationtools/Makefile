# $NetBSD: Makefile,v 1.5 2012/10/02 21:25:46 asau Exp $

PKGNAME=	${DISTNAME:C/-/90-replicationtools-/}
COMMENT=	PostgreSQL replication tools

.include "../../databases/postgresql90/Makefile.common"

BUILD_DIRS+=		contrib/pg_archivecleanup
BUILD_DIRS+=		contrib/pg_standby

.include "../../databases/postgresql90-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
