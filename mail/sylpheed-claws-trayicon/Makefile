# $NetBSD: Makefile,v 1.4 2004/03/26 02:27:45 wiz Exp $
#

PLUGIN_NAME=	trayicon
.include "../../mail/sylpheed-claws/plugins.mk"

PKGREVISION=	2

MAINTAINER=	cube@NetBSD.org
COMMENT=	Plugin to make Sylpheed-claws display an icon in the system tray

CONFIGURE_ARGS+=	--enable-trayicon-plugin

.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
