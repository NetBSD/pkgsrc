# $NetBSD: Makefile,v 1.12 2009/09/15 10:28:29 drochner Exp $
#
PKG_DESTDIR_SUPPORT=	user-destdir

PLUGIN_NAME=	trayicon
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	smb@NetBSD.org
COMMENT=	Places an icon in the system tray for new mail

CONFIGURE_ARGS+=	--enable-trayicon-plugin

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail

.include "../../mail/claws-mail/Makefile.vers"

.include "../../mk/bsd.pkg.mk"
