# $NetBSD: Makefile,v 1.3 2004/11/29 15:14:48 wiz Exp $
#

DISTNAME=		inkscape-0.39
PKGREVISION=		2
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=inkscape/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.inkscape.org/
COMMENT=		Scalable Vector Graphics (SVG) editor

.if ! exists (/usr/bin/iconv)
BUILD_DEPENDS+=		libiconv-[0-9]*:../../converters/libiconv
.endif

GCC_REQD=		3.0
USE_LANGUAGES=		c c++
USE_BUILDLINK3=		yes
USE_DIRS+=		xdg-1.1
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/gtkspell/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
