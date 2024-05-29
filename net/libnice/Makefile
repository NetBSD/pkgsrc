# $NetBSD: Makefile,v 1.78 2024/05/29 16:33:57 adam Exp $

PKGREVISION= 2
.include "Makefile.common"

PKGCONFIG_OVERRIDE+=		output/meson-private/nice.pc
PKGCONFIG_OVERRIDE_STAGE=	pre-install

MESON_ARGS+=	-Dgupnp=enabled
MESON_ARGS+=	-Dgstreamer=disabled

BUILDLINK_DEPMETHOD.gobject-introspection=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
