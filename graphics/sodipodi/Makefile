# $NetBSD: Makefile,v 1.1.1.1 2001/08/10 06:36:09 manu Exp $
#

DISTNAME=	sodipodi-0.23
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sodipodi/}

MAINTAINER=	manu@netbsd.org
HOMEPAGE=	http://www.gnome.org/gnome-office/sodipodi.shtml
COMMENT=	Open source vector graphics drawing program using SVG as native format

DEPENDS+=	gnome-libs>=1.2.13:../../x11/gnome-libs
DEPENDS+=	gnome-print>=0.28:../../print/gnome-print
DEPENDS+=	bonobo>=1.0.4:../../devel/bonobo
DEPENDS+=	libxml>=1.8.11:../../textproc/libxml
DEPENDS+=	gtk+>=1.2.8:../../x11/gtk
DEPENDS+=	pth>=1.3.7:../../devel/pth
DEPENDS+=	xpm>=3.4k:../../graphics/xpm
DEPENDS+=	ORBit>=0.5.8:../../net/ORBit
DEPENDS+=	gal>=0.7:../../devel/gal

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_LIBTOOL=	YES
USE_X11BASE=	YES
USE_LIBINTL=	YES

.include "../../mk/bsd.pkg.mk"
