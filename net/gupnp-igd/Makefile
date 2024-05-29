# $NetBSD: Makefile,v 1.60 2024/05/29 16:33:54 adam Exp $

DISTNAME=	gupnp-igd-1.6.0
PKGREVISION=	2
CATEGORIES=	net devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gupnp-igd/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/GUPnP
COMMENT=	Library to handle UPnP IGD port mapping
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=		output/meson-private/gupnp-igd-1.6.pc
PKGCONFIG_OVERRIDE_STAGE=	pre-install

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.14.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_DEPMETHOD.gobject-introspection=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../net/gupnp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
