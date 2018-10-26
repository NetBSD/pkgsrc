# $NetBSD: Makefile,v 1.3 2018/10/26 11:11:33 jperkin Exp $

PKGREVISION= 1
.include "../../databases/lua-sql-mysql/Makefile.common"

PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/luasql/sql-postgres/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	PostgreSQL bindings for Lua

BUILD_TARGET=	postgres

# Abuse DRIVER_INCS to get our compiler flags into the build
MAKE_FLAGS+=	DRIVER_INCS="${CFLAGS} ${COMPILER_RPATH_FLAG}${PGSQL_PREFIX}/lib -L${PGSQL_PREFIX}/lib"

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
