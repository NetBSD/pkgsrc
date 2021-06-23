# $NetBSD: Makefile,v 1.3 2021/06/23 20:33:07 nia Exp $

.include "Makefile.common"

PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/luasql/sql-mysql/}
PKGREVISION=	1

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	MySQL bindings for Lua

BUILD_TARGET=	mysql

# Abuse DRIVER_INCS to get our compiler flags into the build
MAKE_FLAGS+=	DRIVER_INCS="${CFLAGS} ${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.mysql-client}/lib -L${BUILDLINK_PREFIX.mysql-client}/lib"

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
