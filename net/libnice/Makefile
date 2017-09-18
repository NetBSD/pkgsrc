# $NetBSD: Makefile,v 1.47 2017/09/18 09:53:03 maya Exp $

PKGREVISION= 2
.include "Makefile.common"

# introspection Makefile uses GNUisms
USE_TOOLS+=	gmake
CONFIGURE_ARGS+= --without-gstreamer

PKGCONFIG_OVERRIDE+=	nice/nice.pc.in

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
