# $NetBSD: Makefile,v 1.52 2018/10/24 21:11:47 leot Exp $

PKGREVISION= 7
.include "Makefile.common"

# introspection Makefile uses GNUisms
USE_TOOLS+=	gmake
CONFIGURE_ARGS+= --without-gstreamer

PKGCONFIG_OVERRIDE+=	nice/nice.pc.in

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
