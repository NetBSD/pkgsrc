# $NetBSD: Makefile,v 1.27 2004/10/03 00:14:58 tv Exp $
#

DISTNAME=	sodipodi-0.34
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sodipodi/}

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://www.gnome.org/gnome-office/sodipodi.shtml
COMMENT=	Open source vector graphics drawing program using SVG as native format

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_DIRS+=		gnome2-1.5
USE_PKGLOCALEDIR=	YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES
USE_X11=		YES

REPLACE_PERL=		extensions/*.pl

# force usage of Xft
CONFIGURE_ARGS+=	--with-xft
CONFIGURE_ARGS+=	--without-gnome-print
# needed by configure script for Xft detection
CPPFLAGS+=		-I${BUILDLINK_PREFIX.freetype2}/include/freetype2

LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
