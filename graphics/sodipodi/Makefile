# $NetBSD: Makefile,v 1.25 2004/03/28 21:02:55 xtraeme Exp $
#

DISTNAME=	sodipodi-0.34
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sodipodi/}

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://www.gnome.org/gnome-office/sodipodi.shtml
COMMENT=	Open source vector graphics drawing program using SVG as native format

DEPENDS+=	gnome2-dirs>=1.5:../../misc/gnome2-dirs

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
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
