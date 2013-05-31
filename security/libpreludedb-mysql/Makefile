# $NetBSD: Makefile,v 1.11 2013/05/31 12:41:51 wiz Exp $
#

PKGNAME=		libpreludedb-mysql-${VERSION}
PKGREVISION=		8
COMMENT=		MySQL plugin for LibPreludeDB

.include "../../security/libpreludedb/Makefile.common"

CONFIGURE_ARGS+=	--with-perl=no
CONFIGURE_ARGS+=	--with-python=no
CONFIGURE_ARGS+=	--with-sqlite3=no
CONFIGURE_ARGS+=	--with-postgresql=no

BUILD_DIRS=		plugins/sql

CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}/bin/mysql_config

.include "../../mk/mysql.buildlink3.mk"
.include "../../security/libpreludedb/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
