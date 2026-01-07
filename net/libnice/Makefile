# $NetBSD: Makefile,v 1.87 2026/01/07 08:48:21 wiz Exp $

PKGREVISION= 1
.include "Makefile.common"

PKGCONFIG_OVERRIDE+=		output/meson-private/nice.pc
PKGCONFIG_OVERRIDE_STAGE=	pre-install

MESON_ARGS+=	-Dgupnp=enabled
MESON_ARGS+=	-Dgstreamer=disabled

BUILDLINK_DEPMETHOD.gobject-introspection=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
