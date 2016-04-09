# $NetBSD: Makefile,v 1.5 2016/04/09 12:51:48 adam Exp $

PKGNAME=	${DISTNAME:C/-/93-replicationtools-/}
COMMENT=	PostgreSQL replication tools

.include "../../databases/postgresql93/Makefile.common"

BUILD_DIRS+=		contrib/pg_archivecleanup
BUILD_DIRS+=		contrib/pg_standby

.include "../../databases/postgresql93-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
