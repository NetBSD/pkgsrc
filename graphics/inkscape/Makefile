# $NetBSD: Makefile,v 1.111 2015/01/08 10:20:34 wiz Exp $

DISTNAME=	inkscape-0.48.5
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=inkscape/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.inkscape.org/
COMMENT=	Scalable Vector Graphics (SVG) editor
LICENSE=	gnu-gpl-v2

.if !exists (/usr/bin/iconv)
BUILD_DEPENDS+=		libiconv-[0-9]*:../../converters/libiconv
.endif
DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
# for inkex.py, needed by most python extension scripts
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml

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

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 0.48.4
REPLACE_PYTHON+=	cxxtest/cxxtestgen.py
REPLACE_PYTHON+=	share/filters/i18n.py
REPLACE_PYTHON+=	share/extensions/*.py
REPLACE_PYTHON+=	share/extensions/test/*.test.py
REPLACE_PYTHON+=	share/extensions/Barcode/*.py
REPLACE_PYTHON+=	share/patterns/i18n.py

# XXX I don't see where this is used
CHECK_INTERPRETER_SKIP+= share/inkscape/extensions/simplepath.rb

# XXX these libraries are not auto-detected, at least on Darwin
LDFLAGS.Darwin=		-lfontconfig -lpangoft2-1.0

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
BUILDLINK_API_DEPENDS.boehm-gc+=	boehm-gc>=7.4
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
