# $NetBSD: Makefile,v 1.9 2014/02/23 11:25:52 adam Exp $

PKGNAME=	${DISTNAME:C/-/91-replicationtools-/}
COMMENT=	PostgreSQL replication tools

.include "../../databases/postgresql91/Makefile.common"

BUILD_DIRS+=		contrib/pg_archivecleanup
BUILD_DIRS+=		contrib/pg_standby

.include "../../databases/postgresql91-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
