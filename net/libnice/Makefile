# $NetBSD: Makefile,v 1.46 2017/04/22 21:03:15 adam Exp $

PKGREVISION= 1
.include "Makefile.common"

# introspection Makefile uses GNUisms
USE_TOOLS+=	gmake
CONFIGURE_ARGS+= --without-gstreamer

PKGCONFIG_OVERRIDE+=	nice/nice.pc.in

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
