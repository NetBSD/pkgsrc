# $NetBSD: Makefile,v 1.6 2012/12/16 01:52:05 obache Exp $

PKGNAME=	${DISTNAME:C/-/90-replicationtools-/}
PKGREVISION=	1
COMMENT=	PostgreSQL replication tools

.include "../../databases/postgresql90/Makefile.common"

BUILD_DIRS+=		contrib/pg_archivecleanup
BUILD_DIRS+=		contrib/pg_standby

.include "../../databases/postgresql90-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
