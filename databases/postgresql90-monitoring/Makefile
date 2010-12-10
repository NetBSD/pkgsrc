# $NetBSD: Makefile,v 1.1.1.1 2010/12/10 19:21:06 asau Exp $

PKGNAME=	postgresql90-monitoring-${BASE_VERS}
COMMENT=	PostgreSQL monitoring tools

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	postgresql90-server>=${BASE_VERS}:../../databases/postgresql90-server

.include "../../databases/postgresql90/Makefile.common"

BUILD_DIRS+=		contrib/auto_explain
BUILD_DIRS+=		contrib/pg_buffercache
BUILD_DIRS+=		contrib/pg_stat_statements
BUILD_DIRS+=		contrib/pgstattuple

USE_LIBTOOL=		yes
PKG_LIBTOOL=		${PKG_SHLIBTOOL}

.include "../../databases/postgresql90-client/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
