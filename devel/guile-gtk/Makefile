# $NetBSD: Makefile,v 1.18 2004/10/03 00:13:28 tv Exp $
#

DISTNAME=		guile-gtk-0.19
PKGREVISION=		5
CATEGORIES=		devel x11
MASTER_SITES=		http://www.ping.de/sites/zagadka/guile-gtk/download/ \
			http://erin.netpedia.net/download/ \
			http://erin.linuxbox.com/guile-gtk/download/ \
			http://linux.cem.itesm.mx/~jarios/guile-gtk/download/

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.ping.de/sites/zagadka/guile-gtk/
COMMENT=		Library to make GTK accessible from guile

USE_BUILDLINK3=		# defined
USE_X11=		# defined
USE_LIBTOOL=		# defined

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--datadir=${PREFIX}/${GUILE14_SUBDIR}/share
PLIST_SUBST+=		GUILE14_SUBDIR=${GUILE14_SUBDIR:Q}
MAKE_ENV+=		MACHINE_ARCH=${MACHINE_ARCH}

.include "../../lang/guile14/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
