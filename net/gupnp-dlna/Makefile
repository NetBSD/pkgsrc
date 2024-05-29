# $NetBSD: Makefile,v 1.49 2024/05/29 16:33:54 adam Exp $

DISTNAME=	gupnp-dlna-0.12.0
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gupnp-dlna/${PKGVERSION_NOREV:R}//}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/GUPnP
COMMENT=	Small DLNA-related utility library
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=		output/meson-private/gupnp-dlna-2.0.pc
PKGCONFIG_OVERRIDE+=		output/meson-private/gupnp-dlna-gst-2.0.pc
PKGCONFIG_OVERRIDE+=		output/meson-private/gupnp-dlna-metadata-2.0.pc
PKGCONFIG_OVERRIDE_STAGE=	pre-install

.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../net/gupnp/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
