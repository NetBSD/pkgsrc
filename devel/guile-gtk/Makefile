# $NetBSD: Makefile,v 1.7 2001/02/16 14:38:30 wiz Exp $
#

DISTNAME=		guile-gtk-0.19
CATEGORIES=		devel x11
MASTER_SITES=		http://www.ping.de/sites/zagadka/guile-gtk/download/ \
			http://erin.netpedia.net/download/ \
			http://erin.linuxbox.com/guile-gtk/download/ \
			http://linux.cem.itesm.mx/~jarios/guile-gtk/download/

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.ping.de/sites/zagadka/guile-gtk/
COMMENT=		Library to make GTK accesible from guile

DEPENDS+=		gtk+-1.2.*:../../x11/gtk
DEPENDS+=		guile>=1.4:../../lang/guile

USE_X11=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		# defined

.include "../../mk/bsd.pkg.mk"
