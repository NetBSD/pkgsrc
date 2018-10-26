# $NetBSD: Makefile,v 1.2 2018/10/26 11:11:33 jperkin Exp $

.include "../../databases/lua-sql-mysql/Makefile.common"

PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/luasql/sql-sqlite/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	SQLite 2.x bindings for Lua

BUILD_TARGET=	sqlite

# Abuse DRIVER_INCS to get our compiler flags into the build
MAKE_FLAGS+=	DRIVER_INCS="${CFLAGS} ${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.sqlite}/lib -L${BUILDLINK_PREFIX.sqlite}/lib"

.include "../../databases/sqlite/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
