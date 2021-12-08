# $NetBSD: Makefile,v 1.66 2021/12/08 16:02:29 adam Exp $

PKGREVISION= 9
.include "Makefile.common"

# introspection Makefile uses GNUisms
USE_TOOLS+=		gmake
CONFIGURE_ARGS+=	--without-gstreamer

PKGCONFIG_OVERRIDE+=	nice/nice.pc.in

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
