# $NetBSD: Makefile,v 1.62 2020/06/02 08:22:53 adam Exp $

PKGREVISION= 5
.include "Makefile.common"

# introspection Makefile uses GNUisms
USE_TOOLS+=		gmake
CONFIGURE_ARGS+=	--without-gstreamer

PKGCONFIG_OVERRIDE+=	nice/nice.pc.in

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
