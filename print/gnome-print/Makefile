# $NetBSD: Makefile,v 1.1.1.1 1999/07/31 19:13:07 rh Exp $
#

DISTNAME=	gnome-print-0.4
CATEGORIES=	print
MASTER_SITES=	http://gd.tuwien.ac.at/hci/gnome.org/GNOME/sources/gnome-print/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.levien.com/gnome/print-arch.html

DEPENDS+=	gnome-libs-1.0.10:../../x11/gnome-libs

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_X11BASE=	YES
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include"

.include "../../mk/bsd.pkg.mk"
