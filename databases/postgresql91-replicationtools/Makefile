# $NetBSD: Makefile,v 1.10 2016/03/05 11:28:14 jperkin Exp $

PKGNAME=	${DISTNAME:C/-/91-replicationtools-/}
PKGREVISION=	1
COMMENT=	PostgreSQL replication tools

.include "../../databases/postgresql91/Makefile.common"

BUILD_DIRS+=		contrib/pg_archivecleanup
BUILD_DIRS+=		contrib/pg_standby

.include "../../databases/postgresql91-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
