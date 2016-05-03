# $NetBSD: Makefile,v 1.43 2016/05/03 11:40:07 prlw1 Exp $

PKGREVISION= 3
.include "Makefile.common"

# introspection Makefile uses GNUisms
USE_TOOLS+=	gmake
# configure flag is broken in at least 0.1.13
# http://phabricator.freedesktop.org/T127
#CONFIGURE_ARGS+= --without-gstreamer
CONFIGURE_ARGS+=	have_gst_check=no

PKGCONFIG_OVERRIDE+=	nice/nice.pc.in

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
