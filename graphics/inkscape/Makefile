# $NetBSD: Makefile,v 1.48 2010/02/09 10:12:13 adam Exp $

DISTNAME=	inkscape-0.47
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=inkscape/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.inkscape.org/
COMMENT=	Scalable Vector Graphics (SVG) editor

PKG_DESTDIR_SUPPORT=	user-destdir

.if !exists (/usr/bin/iconv)
BUILD_DEPENDS+=		libiconv-[0-9]*:../../converters/libiconv
.endif

EXTRACT_USING=		bsdtar
GCC_REQD+=		3.0
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt perl:run pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		MSGFMT=${TOOLS_DIR}/bin/msgfmt
CONFIGURE_ENV+=		GMSGFMT=${TOOLS_DIR}/bin/msgfmt

REPLACE_PERL+=		share/extensions/*.p[lm]
REPLACE_PERL+=		share/extensions/svg_dropshadow

BUILDLINK_API_DEPENDS.boehm-gc+=	boehm-gc>=6.4
BUILDLINK_API_DEPENDS.poppler+=		poppler>=0.5.9

UNLIMIT_RESOURCES=	datasize

PKG_OPTIONS_VAR= PKG_OPTIONS.inkscape
PKG_SUPPORTED_OPTIONS= gnome
PKG_SUGGESTED_OPTIONS= gnome

.include "../../mk/bsd.options.mk"

# gnome-vfs support for the inkscape file open window.
.if !empty(PKG_OPTIONS:Mgnome)
CONFIGURE_ARGS+= --with-gnome-vfs
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.endif

BUILDLINK_API_DEPENDS.poppler-includes+= poppler-includes>=0.12.2
.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../print/poppler-glib/buildlink3.mk"
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/gtkspell/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
