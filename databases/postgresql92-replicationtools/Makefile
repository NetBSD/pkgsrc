# $NetBSD: Makefile,v 1.8 2016/04/09 12:51:47 adam Exp $

PKGNAME=	${DISTNAME:C/-/92-replicationtools-/}
COMMENT=	PostgreSQL replication tools

.include "../../databases/postgresql92/Makefile.common"

BUILD_DIRS+=		contrib/pg_archivecleanup
BUILD_DIRS+=		contrib/pg_standby

.include "../../databases/postgresql92-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
