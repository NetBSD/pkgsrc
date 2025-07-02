# $NetBSD: Makefile,v 1.8 2025/07/02 06:09:15 markd Exp $

.include "../../devel/thrift/Makefile.common"

PKGNAME=	lua-${DISTNAME}
COMMENT=	Lua bindings for the Apache Thrift RPC system

DEPENDS+=	thrift-[0-9]*:../../devel/thrift
BUILD_DIRS=	lib/lua

TOOLS_BROKEN+=	perl

CONFIGURE_ARGS+=	--without-go # puts garbage into Makefile
CONFIGURE_ARGS+=	--without-rs # puts garbage into Makefile
CONFIGURE_ENV+=		THRIFT=${PREFIX}/bin/thrift

.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
