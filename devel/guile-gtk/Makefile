# $NetBSD: Makefile,v 1.5 2000/08/05 19:04:44 jlam Exp $
#

DISTNAME=		guile-gtk-0.19
CATEGORIES=		devel x11 gnome
MASTER_SITES=		http://www.ping.de/sites/zagadka/guile-gtk/download/ \
			http://erin.netpedia.net/download/ \
			http://erin.linuxbox.com/guile-gtk/download/ \
			http://linux.cem.itesm.mx/~jarios/guile-gtk/download/

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.ping.de/sites/zagadka/guile-gtk/

DEPENDS+=		gtk+-1.2.*:../../x11/gtk
DEPENDS+=		guile>=1.4:../../lang/guile

USE_X11=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		# defined

.include "../../mk/bsd.pkg.mk"
