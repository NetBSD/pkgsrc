# $NetBSD: Makefile,v 1.1 2016/02/25 21:37:36 tnn Exp $

PKGNAME=	${DISTNAME:C/-/95-replicationtools-/}
COMMENT=	PostgreSQL replication tools

.include "../../databases/postgresql95/Makefile.common"

BUILD_DIRS+=		contrib/pg_standby

.include "../../databases/postgresql95-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
