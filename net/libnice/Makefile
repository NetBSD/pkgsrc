# $NetBSD: Makefile,v 1.45 2017/04/19 13:28:05 wiz Exp $

.include "Makefile.common"

# introspection Makefile uses GNUisms
USE_TOOLS+=	gmake
CONFIGURE_ARGS+= --without-gstreamer

PKGCONFIG_OVERRIDE+=	nice/nice.pc.in

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
