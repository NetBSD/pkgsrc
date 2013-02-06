# $NetBSD: Makefile,v 1.6 2013/02/06 23:22:00 jperkin Exp $

PKGNAME=	${DISTNAME:C/-/91-replicationtools-/}
PKGREVISION=	2
COMMENT=	PostgreSQL replication tools

.include "../../databases/postgresql91/Makefile.common"

BUILD_DIRS+=		contrib/pg_archivecleanup
BUILD_DIRS+=		contrib/pg_standby

.include "../../databases/postgresql91-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
