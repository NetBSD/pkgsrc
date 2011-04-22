# $NetBSD: Makefile,v 1.5 2011/04/22 13:44:36 obache Exp $
#

PKGNAME=		libpreludedb-pgsql-${VERSION}
PKGREVISION=		3
COMMENT=		PostgreSQL plugin for LibPreludeDB

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../security/libpreludedb/Makefile.common"

CONFIGURE_ARGS+=	--with-perl=no
CONFIGURE_ARGS+=	--with-python=no
CONFIGURE_ARGS+=	--with-mysql=no
CONFIGURE_ARGS+=	--with-sqlite3=no

BUILD_DIRS=		plugins/sql

CONFIGURE_ARGS+=	--with-postgresql=${PGSQL_PREFIX}/bin/pg_config

.include "../../mk/pgsql.buildlink3.mk"
.include "../../security/libpreludedb/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
