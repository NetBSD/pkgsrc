# $NetBSD: Makefile,v 1.2 2018/10/26 11:11:33 jperkin Exp $

.include "Makefile.common"

PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/luasql/sql-mysql/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	MySQL bindings for Lua

BUILD_TARGET=	mysql

# Abuse DRIVER_INCS to get our compiler flags into the build
MAKE_FLAGS+=	DRIVER_INCS="${CFLAGS} ${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.mysql-client}/lib -L${BUILDLINK_PREFIX.mysql-client}/lib"

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
