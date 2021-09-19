# $NetBSD: Makefile,v 1.33 2021/09/19 08:06:20 nia Exp $

DISTNAME=	gdk-pixbuf-xlib-2.40.2
# historical reasons
PKGNAME=	${DISTNAME:S/pixbuf/pixbuf2/}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gdk-pixbuf-xlib/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.gnome.org/Archive/gdk-pixbuf-xlib
COMMENT=	Deprecated Xlib integration for GdkPixbuf
LICENSE=	gnu-gpl-v2

CONFLICTS+=	gtk2+<2.22

USE_TOOLS+=	msgfmt pkg-config
MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/gdk-pixbuf-xlib

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE=		output/meson-private/gdk-pixbuf-xlib-2.0.pc

PYTHON_FOR_BUILD_ONLY=	tool

.include "../../devel/meson/build.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
