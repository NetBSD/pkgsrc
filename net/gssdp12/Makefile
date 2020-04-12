# $NetBSD: Makefile,v 1.8 2020/04/12 08:28:02 adam Exp $

DISTNAME=	gssdp-1.2.2
PKGNAME=	${DISTNAME:S/gssdp/gssdp12/}
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gssdp/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gupnp.org/
COMMENT=	Simple Service Discovery Protocol library and device sniffer
LICENSE=	gnu-lgpl-v2

USE_TOOLS+=	pkg-config

# needs GTK3+
MESON_ARGS+=	-Dsniffer=false
# needs gtk-doc
MESON_ARGS+=	-Dgtk-doc=false

PKGCONFIG_OVERRIDE+=		output/meson-private/gssdp-1.2.pc
PKGCONFIG_OVERRIDE_STAGE=	pre-install
MAKE_ENV+=			LD_LIBRARY_PATH=${WRKSRC}/output/libgssdp

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.54.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_DEPMETHOD.gobject-introspection=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
