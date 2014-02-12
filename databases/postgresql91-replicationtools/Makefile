# $NetBSD: Makefile,v 1.8 2014/02/12 23:17:43 tron Exp $

PKGNAME=	${DISTNAME:C/-/91-replicationtools-/}
PKGREVISION=	1
COMMENT=	PostgreSQL replication tools

.include "../../databases/postgresql91/Makefile.common"

BUILD_DIRS+=		contrib/pg_archivecleanup
BUILD_DIRS+=		contrib/pg_standby

.include "../../databases/postgresql91-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
