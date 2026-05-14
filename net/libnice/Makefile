# $NetBSD: Makefile,v 1.89 2026/05/14 16:41:46 ryoon Exp $

PKGREVISION= 3
.include "Makefile.common"

PKGCONFIG_OVERRIDE+=		output/meson-private/nice.pc
PKGCONFIG_OVERRIDE_STAGE=	pre-install

MESON_ARGS+=	-Dgupnp=enabled
MESON_ARGS+=	-Dgstreamer=disabled

BUILDLINK_DEPMETHOD.gobject-introspection=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
