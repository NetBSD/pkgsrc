# $NetBSD: Makefile,v 1.34 2005/10/10 13:58:59 jmmv Exp $
#

DISTNAME=	librsvg-2.12.6
PKGNAME=	${DISTNAME:S/-/2-/}
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/librsvg/2.12/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://librsvg.sourceforge.net/
COMMENT=	SVG library for GNOME2

CONFLICTS+=	librsvg2-gtk-[0-9]*

GNU_CONFIGURE=		YES
USE_DIRS+=		xdg-1.1
USE_LIBTOOL=		YES
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE=	librsvg-2.0.pc.in

CONFIGURE_ARGS+=	--disable-gtk-doc
CONFIGURE_ARGS+=	--with-gimp=no
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/librsvg2
CONFIGURE_ARGS+=	--with-tags=

CFLAGS.Darwin+=		-flat_namespace -undefined suppress
LDFLAGS.Darwin+=	-lfreetype -lfontconfig

GTK2_LOADERS=		YES

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/libcroco/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/modules.mk"
.include "../../mk/bsd.pkg.mk"
