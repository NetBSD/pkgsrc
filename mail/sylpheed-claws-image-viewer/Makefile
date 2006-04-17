# $NetBSD: Makefile,v 1.10 2006/04/17 13:46:38 wiz Exp $
#

PLUGIN_NAME=	image_viewer
.include "../../mail/sylpheed-claws/plugins.mk"

PKGREVISION=	2
MAINTAINER=	cube@NetBSD.org
COMMENT=	Plugin to allow Sylpheed-claws to display images attached to mails

CONFIGURE_ARGS+=	--enable-image-viewer-plugin

.include "../../graphics/imlib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
