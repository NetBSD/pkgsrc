# $NetBSD: Makefile,v 1.83 2025/04/19 07:58:12 wiz Exp $

PKGREVISION= 7
.include "Makefile.common"

PKGCONFIG_OVERRIDE+=		output/meson-private/nice.pc
PKGCONFIG_OVERRIDE_STAGE=	pre-install

MESON_ARGS+=	-Dgupnp=enabled
MESON_ARGS+=	-Dgstreamer=disabled

BUILDLINK_DEPMETHOD.gobject-introspection=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
