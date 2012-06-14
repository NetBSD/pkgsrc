# $NetBSD: Makefile,v 1.3 2012/06/14 07:45:35 sbd Exp $

PKGNAME=	${DISTNAME:C/-/90-replicationtools-/}
PKGREVISION=	1
COMMENT=	PostgreSQL replication tools

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../databases/postgresql90/Makefile.common"

BUILD_DIRS+=		contrib/pg_archivecleanup
BUILD_DIRS+=		contrib/pg_standby

.include "../../databases/postgresql90-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
