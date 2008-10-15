# $NetBSD: Makefile,v 1.10 2008/10/15 16:22:02 smb Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir

PLUGIN_NAME=	dillo_viewer
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	smb@NetBSD.org
COMMENT=	Plugin to use the Dillo web browser for html rendering

CONFIGURE_ARGS+=	--enable-dillo_viewer-plugin

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail
DEPENDS+=	dillo>=0.8.6nb2:../../www/dillo

.include "../../mail/claws-mail/Makefile.vers"
.include "../../security/gnutls/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
