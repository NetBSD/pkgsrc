# $NetBSD: Makefile,v 1.1 2007/08/03 02:35:00 smb Exp $
#

PLUGIN_NAME=	trayicon
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	smb@NetBSD.org
COMMENT=	Places an icon in the system tray for new mail

CONFIGURE_ARGS+=	--enable-trayicon-plugin

DEPENDS+=	claws-mail>=2.10.0:../../mail/claws-mail

.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
