# $NetBSD: Makefile,v 1.18 2003/11/12 01:31:50 salo Exp $
#

DISTNAME=	sodipodi-0.31
PKGREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sodipodi/}

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://www.gnome.org/gnome-office/sodipodi.shtml
COMMENT=	Open source vector graphics drawing program using SVG as native format

DEPENDS+=	gnome2-dirs>=1.0:../../misc/gnome2-dirs

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
USE_X11BASE=		YES

# force usage of Xft
CONFIGURE_ARGS+=	--with-xft
# needed by configure script for Xft detection
CPPFLAGS+=		-I${BUILDLINK_PREFIX.freetype2}/include/freetype2

LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

.include "../../graphics/libart2/buildlink2.mk"
.include "../../print/libgnomeprintui/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
