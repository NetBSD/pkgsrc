# $NetBSD: Makefile,v 1.2 2020/05/13 03:40:29 rillig Exp $

.include "../../devel/thrift/Makefile.common"

PKGNAME=	lua-${DISTNAME}
COMMENT=	Lua bindings for the Apache Thrift RPC system

DEPENDS+=	thrift-[0-9]*:../../devel/thrift
BUILD_DIRS=	lib/lua

TOOLS_BROKEN+=	perl
CONFIGURE_ENV+=		THRIFT=${PREFIX}/bin/thrift

.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
