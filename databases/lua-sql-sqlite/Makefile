# $NetBSD: Makefile,v 1.1 2016/10/08 12:57:07 kamil Exp $

.include "../../databases/lua-sql-mysql/Makefile.common"

PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/luasql/sql-sqlite/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	SQLite 2.x bindings for Lua

BUILD_TARGET=	sqlite

MAKE_FLAGS+=	DRIVER_LIBS_sqlite="${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.sqlite}/lib -L${BUILDLINK_PREFIX.sqlite}/lib -lsqlite"
MAKE_FLAGS+=	DRIVER_INCS_sqlite=-I${BUILDLINK_PREFIX.sqlite}/includel

.include "../../databases/sqlite/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
