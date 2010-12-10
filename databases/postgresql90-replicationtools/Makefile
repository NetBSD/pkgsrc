# $NetBSD: Makefile,v 1.1.1.1 2010/12/10 03:51:31 asau Exp $

PKGNAME=	postgresql90-replicationtools-${BASE_VERS}
COMMENT=	PostgreSQL replication tools
MAINTAINER=	pkgsrc-users@NetBSD.org

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../databases/postgresql90/Makefile.common"

BUILD_DIRS+=		contrib/pg_archivecleanup
BUILD_DIRS+=		contrib/pg_standby

.include "../../databases/postgresql90-client/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
