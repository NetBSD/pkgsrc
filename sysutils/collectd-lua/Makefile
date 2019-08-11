# $NetBSD: Makefile,v 1.3 2019/08/11 13:23:04 wiz Exp $

COLLECTD_PACKAGE=	lua
COLLECTD_PLUGINS=	lua

COMMENT=		Statistics collection daemon - lua plugin
PKGREVISION=		2

.include "../../sysutils/collectd/Makefile.common"

CONFIGURE_ARGS+=	--enable-lua

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
