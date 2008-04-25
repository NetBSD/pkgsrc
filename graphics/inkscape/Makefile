# $NetBSD: Makefile,v 1.38 2008/04/25 22:35:38 wiz Exp $

DISTNAME=	inkscape-0.46
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

GCC_REQD+=		3.0
USE_DIRS+=		xdg-1.1
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

UNLIMIT_RESOURCES=	datasize

.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../textproc/gtkspell/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
