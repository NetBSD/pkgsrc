# $NetBSD: Makefile,v 1.9 2003/01/07 11:43:12 uebayasi Exp $
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

USE_BUILDLINK2=		# defined
USE_X11=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		# defined

.include "../../lang/guile14/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
