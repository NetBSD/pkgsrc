# $NetBSD: Makefile,v 1.2 2004/01/03 18:49:45 reed Exp $
#

PLUGIN_NAME=	image_viewer
.include "../../mail/sylpheed-claws/plugins.mk"

PKGREVISION=	1

MAINTAINER=	cube@NetBSD.org
COMMENT=	Plugin to allow Sylpheed-claws to display images attached to mails

CONFIGURE_ARGS+=	--enable-image-viewer-plugin

.include "../../x11/gtk/buildlink2.mk"
.include "../../graphics/imlib/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
