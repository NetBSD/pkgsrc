# $NetBSD: Makefile,v 1.1.1.1 2017/07/25 06:48:51 alnsn Exp $

COLLECTD_PACKAGE=	lua
COLLECTD_PLUGINS=	lua

COMMENT=		Statistics collection daemon - lua plugin

.include "../../sysutils/collectd/Makefile.common"

CONFIGURE_ARGS+=	--enable-lua

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
