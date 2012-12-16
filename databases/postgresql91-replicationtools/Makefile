# $NetBSD: Makefile,v 1.5 2012/12/16 01:52:07 obache Exp $

PKGNAME=	${DISTNAME:C/-/91-replicationtools-/}
PKGREVISION=	1
COMMENT=	PostgreSQL replication tools

.include "../../databases/postgresql91/Makefile.common"

BUILD_DIRS+=		contrib/pg_archivecleanup
BUILD_DIRS+=		contrib/pg_standby

.include "../../databases/postgresql91-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
