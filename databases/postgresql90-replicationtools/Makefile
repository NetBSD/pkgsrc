# $NetBSD: Makefile,v 1.10 2014/02/23 11:25:51 adam Exp $

PKGNAME=	${DISTNAME:C/-/90-replicationtools-/}
COMMENT=	PostgreSQL replication tools

.include "../../databases/postgresql90/Makefile.common"

BUILD_DIRS+=		contrib/pg_archivecleanup
BUILD_DIRS+=		contrib/pg_standby

.include "../../databases/postgresql90-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
