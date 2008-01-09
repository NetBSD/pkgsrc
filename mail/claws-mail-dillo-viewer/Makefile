# $NetBSD: Makefile,v 1.5 2008/01/09 03:55:10 smb Exp $
#

PLUGIN_NAME=	dillo_viewer
PLUG_VER=	3.2.0
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	smb@NetBSD.org
COMMENT=	Plugin to use the Dillo web browser for html rendering

CONFIGURE_ARGS+=	--enable-dillo_viewer-plugin

DEPENDS+=	claws-mail-3.2.0{,nb[0-9]*}:../../mail/claws-mail
DEPENDS+=	dillo>=0.8.6nb2:../../www/dillo

.include "../../mail/claws-mail/Makefile.vers"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
