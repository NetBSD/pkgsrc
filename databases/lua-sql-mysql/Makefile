# $NetBSD: Makefile,v 1.1 2016/10/08 12:53:54 kamil Exp $

.include "Makefile.common"

PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/luasql/sql-mysql/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	MySQL bindings for Lua

BUILD_TARGET=	mysql

MAKE_FLAGS+=	DRIVER_LIBS_mysql="${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.mysql-client}/lib -L${BUILDLINK_PREFIX.mysql-client}/lib -lmysqlclient"
MAKE_FLAGS+=	DRIVER_INCS_mysql=-I${BUILDLINK_PREFIX.mysql-client}/include/mysql

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
