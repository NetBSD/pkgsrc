# $NetBSD: Makefile,v 1.7 2005/03/06 16:45:47 chris Exp $
#

PLUGIN_NAME=	trayicon
.include "../../mail/sylpheed-claws/plugins.mk"

MAINTAINER=	cube@NetBSD.org
COMMENT=	Plugin to make Sylpheed-claws display an icon in the system tray

CONFIGURE_ARGS+=	--enable-trayicon-plugin

.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
