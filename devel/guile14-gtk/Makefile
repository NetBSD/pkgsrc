# $NetBSD: Makefile,v 1.7.6.1 2006/10/17 20:37:39 salo Exp $
#

DISTNAME=		guile-gtk-0.19
PKGREVISION=		8
CATEGORIES=		devel x11
MASTER_SITES=		http://www.ping.de/sites/zagadka/guile-gtk/download/ \
			http://erin.netpedia.net/download/ \
			http://erin.linuxbox.com/guile-gtk/download/ \
			http://linux.cem.itesm.mx/~jarios/guile-gtk/download/

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.ping.de/sites/zagadka/guile-gtk/
COMMENT=		Library to make GTK accessible from guile 1.4

USE_LIBTOOL=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--datadir=${PREFIX}/${GUILE14_SUBDIR}/share
PLIST_SUBST+=		GUILE14_SUBDIR=${GUILE14_SUBDIR:Q}
MAKE_ENV+=		MACHINE_ARCH=${MACHINE_ARCH:Q}
LDFLAGS+=		-lltdl

.include "../../lang/guile14/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
