# $NetBSD: Makefile,v 1.1.1.1 1999/08/22 20:27:24 rh Exp $
#

DISTNAME=	ggv-0.50
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.gnome.org/pub/GNOME/sources/ggv/ \
		ftp://ftp.tuwien.ac.at/hci/gnome.org/GNOME/sources/ggv/ \
		http://gd.tuwien.ac.at/hci/gnome.org/GNOME/sources/ggv/ \
		ftp://ftp.circ.us.eu.org/mirrors/ftp.gnome.org/sources/ggv/  \
		ftp://ftp.jimpick.com/pub/mirrors/gnome/sources/ggv/ \
		ftp://ftp.informatik.uni-bonn.de/pub/os/unix/gnome/sources/ggv/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnome.org/

DEPENDS+=	ghostscript-5.50:../../print/ghostscript5
DEPENDS+=	gnome-core-1.0.7:../../x11/gnome-core
DEPENDS+=	pth-1.1.1:../../devel/pth

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_X11=	YES

.include "../../mk/bsd.pkg.mk"
