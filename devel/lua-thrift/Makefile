# $NetBSD: Makefile,v 1.7 2025/03/04 13:05:19 adam Exp $

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
