# $NetBSD: Makefile,v 1.1.1.1 2001/07/22 01:34:20 wiz Exp $

DISTNAME=		eog-0.6
CATEGORIES=		gnome graphics x11
MASTER_SITES=		${MASTER_SITE_GNOME:=unstable/sources/eog/}

MAINTAINER=		epg@pobox.com
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Eye of GNOME: an image viewing and cataloging program

DEPENDS+=		bonobo>=0.37:../../devel/bonobo
DEPENDS+=		GConf>=1.0:../../devel/GConf
DEPENDS+=		gdk-pixbuf-gnome>=0.10.1:../../graphics/gdk-pixbuf-gnome
DEPENDS+=		gnome-print>=0.28:../../print/gnome-print
DEPENDS+=		libglade>=0.16:../../devel/libglade

GNU_CONFIGURE=		YES
USE_X11BASE=		YES
USE_GMAKE=		YES
USE_LIBINTL=		YES

.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../x11/gnome-libs/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
