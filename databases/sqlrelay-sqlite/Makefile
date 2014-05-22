# $NetBSD: Makefile,v 1.1 2014/05/22 12:50:48 fhajny Exp $

PKGNAME=		${DISTNAME:S/sqlrelay/sqlrelay-sqlite/}
COMMENT=		SQLite support for SQL Relay

.include "../../databases/sqlrelay/Makefile.common"

CONFIGURE_ARGS+=	--with-sqlite-prefix=${BUILDLINK_PREFIX.sqlite3}
# Configure never does this correctly
CXXFLAGS+=		-DSQLITE3=1

BUILD_DIRS=		src/connections/sqlite

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../databases/sqlrelay/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
