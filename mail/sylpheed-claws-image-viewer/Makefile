# $NetBSD: Makefile,v 1.9 2006/02/05 23:09:58 joerg Exp $
#

PLUGIN_NAME=	image_viewer
.include "../../mail/sylpheed-claws/plugins.mk"

PKGREVISION=	1
MAINTAINER=	cube@NetBSD.org
COMMENT=	Plugin to allow Sylpheed-claws to display images attached to mails

CONFIGURE_ARGS+=	--enable-image-viewer-plugin

.include "../../graphics/imlib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
