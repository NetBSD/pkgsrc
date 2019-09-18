# $NetBSD: Makefile,v 1.1 2019/09/18 11:27:52 adam Exp $

.include "../../devel/thrift/Makefile.common"

PKGNAME=	lua-${DISTNAME}
COMMENT=	Lua bindings for the Apache Thrift RPC system

DEPENDS+=	thrift-[0-9]*:../../devel/thrift
BUILD_DIRS=	lib/lua

CONFIGURE_ENV+=		THRIFT=${PREFIX}/bin/thrift

.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
