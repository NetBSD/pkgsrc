# $NetBSD: Makefile,v 1.76.2.1 2012/10/03 12:08:05 spz Exp $

DISTNAME=	inkscape-0.48.3.1
PKGREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=inkscape/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.inkscape.org/
COMMENT=	Scalable Vector Graphics (SVG) editor
LICENSE=	gnu-gpl-v2

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
CONFIGURE_ARGS+=	--with-python

REPLACE_PERL+=		share/extensions/*.p[lm]
REPLACE_PERL+=		share/extensions/svg_dropshadow

BUILDLINK_API_DEPENDS.boehm-gc+=	boehm-gc>=6.4
BUILDLINK_API_DEPENDS.poppler+=		poppler>=0.5.9

UNLIMIT_RESOURCES=	datasize

LDFLAGS.DragonFly=	-lX11

SUBST_CLASSES+= pypath
SUBST_STAGE.pypath= pre-configure
SUBST_FILES.pypath= src/extension/implementation/script.cpp
SUBST_VARS.pypath= PYTHONBIN
CHECK_INTERPRETER_SKIP+= share/inkscape/extensions/*.py

# XXX I don't see where this is used
CHECK_INTERPRETER_SKIP+= share/inkscape/extensions/simplepath.rb

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
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../print/poppler-glib/buildlink3.mk"
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/gtkspell/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
