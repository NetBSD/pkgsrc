# $NetBSD: Makefile,v 1.19 2018/08/22 09:46:18 wiz Exp $
#

PKGNAME=		libpreludedb-pgsql-${VERSION}
PKGREVISION=		16
COMMENT=		PostgreSQL plugin for LibPreludeDB

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
