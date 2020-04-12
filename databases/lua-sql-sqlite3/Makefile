# $NetBSD: Makefile,v 1.5 2020/04/12 08:28:25 adam Exp $

PKGREVISION= 3
.include "../../databases/lua-sql-mysql/Makefile.common"

PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/luasql/sql-sqlite3/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	SQLite 3.x bindings for Lua

BUILD_TARGET=	sqlite3

# Abuse DRIVER_INCS to get our compiler flags into the build
MAKE_FLAGS+=	DRIVER_INCS="${CFLAGS} ${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.sqlite3}/lib -L${BUILDLINK_PREFIX.sqlite3}/lib"

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
