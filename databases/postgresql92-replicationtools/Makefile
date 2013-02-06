# $NetBSD: Makefile,v 1.3 2013/02/06 23:22:01 jperkin Exp $

PKGNAME=	${DISTNAME:C/-/92-replicationtools-/}
PKGREVISION=	2
COMMENT=	PostgreSQL replication tools

.include "../../databases/postgresql92/Makefile.common"

BUILD_DIRS+=		contrib/pg_archivecleanup
BUILD_DIRS+=		contrib/pg_standby

.include "../../databases/postgresql92-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
