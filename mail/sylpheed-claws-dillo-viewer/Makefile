# $NetBSD: Makefile,v 1.5 2004/07/18 10:01:02 recht Exp $
#

PLUGIN_NAME=	dillo_viewer
.include "../../mail/sylpheed-claws/plugins.mk"

PKGREVISION=	3

MAINTAINER=	cube@NetBSD.org
COMMENT=	Plugin to allow Sylpheed-claws to render HTML attachments

DEPENDS+=	dillo>=0.7.2:../../www/dillo

CONFIGURE_ARGS+=	--enable-dillo-viewer-plugin

.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
