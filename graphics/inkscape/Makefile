# $NetBSD: Makefile,v 1.26.2.1 2006/10/04 12:05:05 salo Exp $

DISTNAME=	inkscape-0.44
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=inkscape/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.inkscape.org/
COMMENT=	Scalable Vector Graphics (SVG) editor

.if !exists (/usr/bin/iconv)
BUILD_DEPENDS+=		libiconv-[0-9]*:../../converters/libiconv
.endif

GCC_REQD+=		3.0
USE_DIRS+=		xdg-1.1
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
GNU_CONFIGURE=		yes

BUILDLINK_API_DEPENDS.boehm-gc+=	boehm-gc>=6.4

UNLIMIT_RESOURCES=	datasize

.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/gtkspell/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
