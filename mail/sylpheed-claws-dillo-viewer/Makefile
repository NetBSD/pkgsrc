# $NetBSD: Makefile,v 1.7 2005/03/06 16:45:47 chris Exp $
#

PLUGIN_NAME=	dillo_viewer
.include "../../mail/sylpheed-claws/plugins.mk"

MAINTAINER=	cube@NetBSD.org
COMMENT=	Plugin to allow Sylpheed-claws to render HTML attachments

DEPENDS+=	dillo>=0.7.2:../../www/dillo

CONFIGURE_ARGS+=	--enable-dillo-viewer-plugin

.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
