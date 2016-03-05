# $NetBSD: Makefile,v 1.7 2016/03/05 11:28:15 jperkin Exp $

PKGNAME=	${DISTNAME:C/-/92-replicationtools-/}
PKGREVISION=	1
COMMENT=	PostgreSQL replication tools

.include "../../databases/postgresql92/Makefile.common"

BUILD_DIRS+=		contrib/pg_archivecleanup
BUILD_DIRS+=		contrib/pg_standby

.include "../../databases/postgresql92-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
