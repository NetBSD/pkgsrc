# $NetBSD: Makefile,v 1.8 2006/02/05 23:09:58 joerg Exp $
#

PLUGIN_NAME=	trayicon
.include "../../mail/sylpheed-claws/plugins.mk"

PKGREVISION=	1
MAINTAINER=	cube@NetBSD.org
COMMENT=	Plugin to make Sylpheed-claws display an icon in the system tray

CONFIGURE_ARGS+=	--enable-trayicon-plugin

.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
