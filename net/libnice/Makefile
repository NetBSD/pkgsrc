# $NetBSD: Makefile,v 1.48 2017/11/30 16:45:07 adam Exp $

PKGREVISION= 3
.include "Makefile.common"

# introspection Makefile uses GNUisms
USE_TOOLS+=	gmake
CONFIGURE_ARGS+= --without-gstreamer

PKGCONFIG_OVERRIDE+=	nice/nice.pc.in

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
