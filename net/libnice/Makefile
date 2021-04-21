# $NetBSD: Makefile,v 1.65 2021/04/21 13:24:13 adam Exp $

PKGREVISION= 8
.include "Makefile.common"

# introspection Makefile uses GNUisms
USE_TOOLS+=		gmake
CONFIGURE_ARGS+=	--without-gstreamer

PKGCONFIG_OVERRIDE+=	nice/nice.pc.in

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
