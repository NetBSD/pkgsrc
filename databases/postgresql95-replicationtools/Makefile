# $NetBSD: Makefile,v 1.3 2016/04/09 12:51:50 adam Exp $

PKGNAME=	${DISTNAME:C/-/95-replicationtools-/}
COMMENT=	PostgreSQL replication tools

.include "../../databases/postgresql95/Makefile.common"

BUILD_DIRS+=		contrib/pg_standby

.include "../../databases/postgresql95-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
