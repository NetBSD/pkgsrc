# $NetBSD: Makefile,v 1.1.1.1 2004/01/01 21:43:27 cube Exp $
#

PLUGIN_NAME=	trayicon
.include "../../mail/sylpheed-claws/plugins.mk"

MAINTAINER=	cube@NetBSD.org
COMMENT=	Plugin to make Sylpheed-claws display an icon in the system tray

CONFIGURE_ARGS+=	--enable-trayicon-plugin

.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
