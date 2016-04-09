# $NetBSD: Makefile,v 1.3 2016/04/09 12:51:49 adam Exp $

PKGNAME=	${DISTNAME:C/-/94-replicationtools-/}
COMMENT=	PostgreSQL replication tools

.include "../../databases/postgresql94/Makefile.common"

BUILD_DIRS+=		contrib/pg_archivecleanup
BUILD_DIRS+=		contrib/pg_standby

.include "../../databases/postgresql94-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
