# $NetBSD: Makefile,v 1.1 2012/10/05 21:03:12 adam Exp $

PKGNAME=	${DISTNAME:C/-/92-replicationtools-/}
COMMENT=	PostgreSQL replication tools

.include "../../databases/postgresql92/Makefile.common"

BUILD_DIRS+=		contrib/pg_archivecleanup
BUILD_DIRS+=		contrib/pg_standby

.include "../../databases/postgresql92-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
