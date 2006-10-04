# $NetBSD: Makefile,v 1.8 2006/10/04 21:35:59 wiz Exp $
#

DISTNAME=		guile-gtk-0.19
PKGREVISION=		7
CATEGORIES=		devel x11
MASTER_SITES=		http://gnuwin.epfl.ch/sources/geda/

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/guile-gtk/
COMMENT=		Library to make GTK accessible from guile 1.4

USE_LIBTOOL=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--datadir=${PREFIX}/${GUILE14_SUBDIR}/share
PLIST_SUBST+=		GUILE14_SUBDIR=${GUILE14_SUBDIR:Q}
MAKE_ENV+=		MACHINE_ARCH=${MACHINE_ARCH:Q}

.include "../../lang/guile14/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
