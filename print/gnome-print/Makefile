# $NetBSD: Makefile,v 1.4 1999/08/29 12:48:24 rh Exp $
#

DISTNAME=	gnome-print-0.4
CATEGORIES=	print
MASTER_SITES=	http://gd.tuwien.ac.at/hci/gnome.org/GNOME/sources/gnome-print/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.levien.com/gnome/print-arch.html

DEPENDS+=	gnome-libs-1.0.14:../../x11/gnome-libs
DEPENDS+=	libxml-1.4.0:../../textproc/libxml
DEPENDS+=	ghostscript-5.50:../../print/ghostscript5

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_X11BASE=	YES
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include"

.include "../../mk/bsd.pkg.mk"
