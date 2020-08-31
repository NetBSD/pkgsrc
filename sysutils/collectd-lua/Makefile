# $NetBSD: Makefile,v 1.4 2020/08/31 18:11:25 wiz Exp $

COLLECTD_PACKAGE=	lua
COLLECTD_PLUGINS=	lua

COMMENT=		Statistics collection daemon - lua plugin
PKGREVISION=		3

.include "../../sysutils/collectd/Makefile.common"

CONFIGURE_ARGS+=	--enable-lua

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
