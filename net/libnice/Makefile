# $NetBSD: Makefile,v 1.71 2023/01/02 00:11:17 wiz Exp $

PKGREVISION= 14
.include "Makefile.common"

# introspection Makefile uses GNUisms
USE_TOOLS+=		gmake
CONFIGURE_ARGS+=	--without-gstreamer

PKGCONFIG_OVERRIDE+=	nice/nice.pc.in

BUILDLINK_DEPMETHOD.gobject-introspection=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
