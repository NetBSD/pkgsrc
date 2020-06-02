# $NetBSD: Makefile,v 1.6 2020/06/02 08:24:05 adam Exp $

DISTNAME=	librsvg-2.40.21
PKGREVISION=	3
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/librsvg/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/LibRsvg
COMMENT=	SVG library for GNOME (2.40.xx branch, C only)
LICENSE=	gnu-lgpl-v2

CONFLICTS+=	librsvg2-gtk-[0-9]* librsvg2-[0-9]*

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config gmake
USE_LANGUAGES+=		c c++
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-tools
CONFIGURE_ARGS+=	--enable-Bsymbolic=auto

PKGCONFIG_OVERRIDE=	librsvg.pc.in

TEST_TARGET=		check

CONFIGURE_ARGS.Darwin+=	--disable-Bsymbolic

PKG_OPTIONS_VAR=	PKG_OPTIONS.librsvg
PKG_SUPPORTED_OPTIONS=	introspection
PKG_SUGGESTED_OPTIONS=	introspection
.include "../../mk/bsd.options.mk"

PLIST_VARS+=	introspection

.if !empty(PKG_OPTIONS:Mintrospection)
PLIST.introspection=	yes
CONFIGURE_ARGS+=	--enable-introspection
BUILDLINK_DEPMETHOD.gobject-introspection+=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-introspection
.endif

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.24.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.pango+=	pango>=1.38
.include "../../devel/pango/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.2.0
.include "../../graphics/cairo/buildlink3.mk"
BUILDLINK_DEPMETHOD.cairo-gobject+=	build
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/loaders.mk"
BUILDLINK_API_DEPENDS.libcroco+=	libcroco>=0.6.1
.include "../../textproc/libcroco/buildlink3.mk"
BUILDLINK_API_DEPENDS.libxml2+=	libxml2>=2.9
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
