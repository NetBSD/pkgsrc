# $NetBSD: Makefile,v 1.6 2022/09/19 17:29:22 nia Exp $

COLLECTD_PACKAGE=	lua
COLLECTD_PLUGINS=	lua

COMMENT=		Statistics collection daemon - lua plugin

.include "../../sysutils/collectd/Makefile.common"

CONFIGURE_ARGS+=	--enable-lua

.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
