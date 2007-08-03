# $NetBSD: Makefile,v 1.1 2007/08/03 02:34:45 smb Exp $
#

PLUGIN_NAME=	dillo_viewer
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	smb@NetBSD.org
COMMENT=	Plugin to use the Dillo web browser for html rendering

CONFIGURE_ARGS+=	--enable-dillo_viewer-plugin

DEPENDS+=	claws-mail>=2.10.0:../../mail/claws-mail
DEPENDS+=	dillo>=0.8.6nb2:../../www/dillo

.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
