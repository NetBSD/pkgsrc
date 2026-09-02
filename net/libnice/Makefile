# $NetBSD: Makefile,v 1.91 2026/09/02 11:11:18 adam Exp $

.include "Makefile.common"

TOOL_DEPENDS+=	glib2-introspection>=0:../../devel/glib2-introspection

PKGCONFIG_OVERRIDE+=		output/meson-private/nice.pc
PKGCONFIG_OVERRIDE_STAGE=	pre-install

MESON_ARGS+=	-Dgupnp=enabled
MESON_ARGS+=	-Dgstreamer=disabled

BUILDLINK_DEPMETHOD.gobject-introspection=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
