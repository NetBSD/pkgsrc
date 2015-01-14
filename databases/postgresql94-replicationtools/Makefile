# $NetBSD: Makefile,v 1.1 2015/01/14 21:01:19 adam Exp $

PKGNAME=	${DISTNAME:C/-/94-replicationtools-/}
COMMENT=	PostgreSQL replication tools

.include "../../databases/postgresql94/Makefile.common"

BUILD_DIRS+=		contrib/pg_archivecleanup
BUILD_DIRS+=		contrib/pg_standby

.include "../../databases/postgresql94-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
