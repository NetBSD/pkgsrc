# $NetBSD: Makefile,v 1.1.1.1 1999/07/31 19:20:32 rh Exp $
#

DISTNAME=	gnumeric-0.31
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.gnome.org/pub/GNOME/sources/gnumeric/ \
		ftp://ftp.tuwien.ac.at/hci/GNOME/sources/gnumeric/ \
		http://gd.tuwien.ac.at/hci/GNOME/sources/gnumeric/ \
		ftp://gnomeftp.wgn.net/pub/gnome/sources/gnumeric/ \
		ftp://ftp.geo.net/pub/gnome/sources/gnumeric/ \
		ftp://ftp.informatik.uni-bonn.de/pub/os/unix/gnome/sources/gnumeric/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnome.org/gnumeric/

DEPENDS+=	gnome-core-1.0.7:../../x11/gnome-core
DEPENDS+=	gnome-print-0.4:../../print/gnome-print
DEPENDS+=	libxml-1.4.0:../../textproc/libxml
DEPENDS+=	libglade-0.2:../../devel/libglade

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_X11BASE=	YES
USE_PERL5=	YES
LDFLAGS+=       -L${LOCALBASE}/lib
CONFIGURE_ENV+= CPPFLAGS="-I${LOCALBASE}/include"

.include "../../mk/bsd.pkg.mk"
