# $NetBSD: Makefile,v 1.8 2021/04/21 11:41:12 adam Exp $

PKGREVISION= 6
.include "../../databases/lua-sql-mysql/Makefile.common"

PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/luasql/sql-sqlite3/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	SQLite 3.x bindings for Lua

BUILD_TARGET=	sqlite3

# Abuse DRIVER_INCS to get our compiler flags into the build
MAKE_FLAGS+=	DRIVER_INCS="${CFLAGS} ${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.sqlite3}/lib -L${BUILDLINK_PREFIX.sqlite3}/lib"

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
