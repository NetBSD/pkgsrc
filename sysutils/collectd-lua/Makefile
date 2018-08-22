# $NetBSD: Makefile,v 1.2 2018/08/22 09:46:32 wiz Exp $

COLLECTD_PACKAGE=	lua
COLLECTD_PLUGINS=	lua

COMMENT=		Statistics collection daemon - lua plugin
PKGREVISION=		1

.include "../../sysutils/collectd/Makefile.common"

CONFIGURE_ARGS+=	--enable-lua

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
