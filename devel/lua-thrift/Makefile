# $NetBSD: Makefile,v 1.5 2021/10/25 16:49:36 adam Exp $

.include "../../devel/thrift/Makefile.common"

PKGNAME=	lua-${DISTNAME}
COMMENT=	Lua bindings for the Apache Thrift RPC system

DEPENDS+=	thrift-[0-9]*:../../devel/thrift
BUILD_DIRS=	lib/lua

TOOLS_BROKEN+=	perl

CONFIGURE_ARGS+=	--without-rs # puts garbage into Makefile
CONFIGURE_ENV+=		THRIFT=${PREFIX}/bin/thrift

.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
