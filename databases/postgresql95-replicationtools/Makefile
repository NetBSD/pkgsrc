# $NetBSD: Makefile,v 1.2.2.1 2016/04/27 20:12:36 bsiegert Exp $

PKGNAME=	${DISTNAME:C/-/95-replicationtools-/}
COMMENT=	PostgreSQL replication tools

.include "../../databases/postgresql95/Makefile.common"

BUILD_DIRS+=		contrib/pg_standby

.include "../../databases/postgresql95-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
