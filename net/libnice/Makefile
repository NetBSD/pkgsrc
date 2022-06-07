# $NetBSD: Makefile,v 1.68 2022/06/07 20:42:41 wiz Exp $

PKGREVISION= 11
.include "Makefile.common"

# introspection Makefile uses GNUisms
USE_TOOLS+=		gmake
CONFIGURE_ARGS+=	--without-gstreamer

PKGCONFIG_OVERRIDE+=	nice/nice.pc.in

BUILDLINK_DEPMETHOD.gobject-introspection=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
