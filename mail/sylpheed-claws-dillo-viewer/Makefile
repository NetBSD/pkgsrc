# $NetBSD: Makefile,v 1.1.1.1 2004/01/01 21:42:34 cube Exp $
#

PLUGIN_NAME=	dillo_viewer
.include "../../mail/sylpheed-claws/plugins.mk"

MAINTAINER=	cube@NetBSD.org
COMMENT=	Plugin to allow Sylpheed-claws to render HTML attachments

DEPENDS+=	dillo>=0.7.2:../../www/dillo

CONFIGURE_ARGS+=	--enable-dillo-viewer-plugin

.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
