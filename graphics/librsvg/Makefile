# $NetBSD: Makefile,v 1.77 2013/12/08 18:21:00 prlw1 Exp $

DISTNAME=	librsvg-2.36.4
PKGREVISION=	7
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/librsvg/2.36/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://live.gnome.org/LibRsvg
COMMENT=	SVG library for GNOME2
LICENSE=	gnu-lgpl-v2

CONFLICTS+=	librsvg2-gtk-[0-9]* librsvg2-[0-9]*
MAKE_JOBS_SAFE=	NO

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
USE_LANGUAGES+=		c c++
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-gtk-theme --disable-tools
CONFIGURE_ARGS+=	--disable-introspection
CONFIGURE_ARGS+=	--enable-Bsymbolic=auto

PKGCONFIG_OVERRIDE=	librsvg.pc.in

TEST_TARGET=		check

BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.2.0
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.24.0

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
CONFIGURE_ARGS+=	--disable-Bsymbolic
.endif

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
BUILDLINK_API_DEPENDS.libcroco+=	libcroco>=0.6.1
.include "../../textproc/libcroco/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/loaders.mk"
.include "../../mk/bsd.pkg.mk"
