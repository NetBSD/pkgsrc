# $NetBSD: Makefile,v 1.8 2005/03/06 16:45:47 chris Exp $
#

PLUGIN_NAME=	image_viewer
.include "../../mail/sylpheed-claws/plugins.mk"

MAINTAINER=	cube@NetBSD.org
COMMENT=	Plugin to allow Sylpheed-claws to display images attached to mails

CONFIGURE_ARGS+=	--enable-image-viewer-plugin

.include "../../graphics/imlib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
