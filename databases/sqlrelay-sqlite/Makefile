# $NetBSD: Makefile,v 1.2 2015/04/06 08:17:24 adam Exp $

PKGNAME=		${DISTNAME:S/sqlrelay/sqlrelay-sqlite/}
PKGREVISION=		1
COMMENT=		SQLite support for SQL Relay

.include "../../databases/sqlrelay/Makefile.common"

CONFIGURE_ARGS+=	--with-sqlite-prefix=${BUILDLINK_PREFIX.sqlite3}
# Configure never does this correctly
CXXFLAGS+=		-DSQLITE3=1

BUILD_DIRS=		src/connections/sqlite

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../databases/sqlrelay/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
