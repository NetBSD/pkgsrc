# $NetBSD: Makefile,v 1.5 2004/07/18 10:01:02 recht Exp $
#

PLUGIN_NAME=	trayicon
.include "../../mail/sylpheed-claws/plugins.mk"

PKGREVISION=	3

MAINTAINER=	cube@NetBSD.org
COMMENT=	Plugin to make Sylpheed-claws display an icon in the system tray

CONFIGURE_ARGS+=	--enable-trayicon-plugin

.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
