# $NetBSD: Makefile,v 1.1.1.1 1999/12/20 11:58:45 rh Exp $
#

DISTNAME=	guile-gtk-0.17
CATEGORIES=	devel x11 gnome
MASTER_SITES=	http://www.ping.de/sites/zagadka/guile-gtk/download/ \
		http://erin.netpedia.net/download/ \
		http://erin.linuxbox.com/guile-gtk/download/ \
		http://linux.cem.itesm.mx/~jarios/guile-gtk/download/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.ping.de/sites/zagadka/guile-gtk/

DEPENDS+=	gnome-core-*:../../x11/gnome-core
DEPENDS+=	guile-1.3.*:../../lang/guile

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_X11=	YES

.include "../../mk/bsd.pkg.mk"
