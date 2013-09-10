# $NetBSD: Makefile,v 1.1 2013/09/10 15:32:33 adam Exp $

PKGNAME=	${DISTNAME:C/-/93-replicationtools-/}
COMMENT=	PostgreSQL replication tools

.include "../../databases/postgresql93/Makefile.common"

BUILD_DIRS+=		contrib/pg_archivecleanup
BUILD_DIRS+=		contrib/pg_standby

.include "../../databases/postgresql93-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
