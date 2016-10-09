# $NetBSD: Makefile,v 1.2 2016/10/09 21:41:56 wiz Exp $

PKGREVISION= 1
.include "../../databases/lua-sql-mysql/Makefile.common"

PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/luasql/sql-postgres/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	PostgreSQL bindings for Lua

BUILD_TARGET=	postgres

MAKE_FLAGS+=	DRIVER_LIBS_postgres="${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.${PGSQL_TYPE}}/lib -L${BUILDLINK_PREFIX.${PGSQL_TYPE}}/lib -lpq"
MAKE_FLAGS+=	DRIVER_INCS_postgres=-I${BUILDLINK_PREFIX.${PGSQL_TYPE}}/include

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
