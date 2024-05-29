# $NetBSD: Makefile,v 1.61 2024/05/29 16:33:54 adam Exp $

DISTNAME=	gupnp-av-0.14.1
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gupnp-av/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/GUPnP
COMMENT=	Helpers for audio/video applications using GUPnP
LICENSE=	gnu-lgpl-v2

USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=		output/meson-private/gupnp-av-1.0.pc
PKGCONFIG_OVERRIDE_STAGE=	pre-install

BUILDLINK_TRANSFORM+=	rm:-Werror=deprecated-declarations

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../net/gupnp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
