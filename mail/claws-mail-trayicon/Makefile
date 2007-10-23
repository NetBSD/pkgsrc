# $NetBSD: Makefile,v 1.4 2007/10/23 20:16:54 smb Exp $
#

PLUGIN_NAME=	trayicon
PLUG_VER=	3.0.1
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	smb@NetBSD.org
COMMENT=	Places an icon in the system tray for new mail
PKGREVISION=	2

CONFIGURE_ARGS+=	--enable-trayicon-plugin

DEPENDS+=	claws-mail>=3.0.1:../../mail/claws-mail

.include "../../mail/claws-mail/Makefile.vers"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
