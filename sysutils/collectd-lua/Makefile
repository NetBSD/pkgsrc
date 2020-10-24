# $NetBSD: Makefile,v 1.5 2020/10/24 22:39:46 wiz Exp $

COLLECTD_PACKAGE=	lua
COLLECTD_PLUGINS=	lua

COMMENT=		Statistics collection daemon - lua plugin

.include "../../sysutils/collectd/Makefile.common"

CONFIGURE_ARGS+=	--enable-lua

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
