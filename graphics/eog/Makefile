# $NetBSD: Makefile,v 1.2 2002/03/13 17:37:05 fredb Exp $

DISTNAME=		eog-0.6
PKGREVISION=		1
CATEGORIES=		gnome graphics x11
MASTER_SITES=		${MASTER_SITE_GNOME:=unstable/sources/eog/}

MAINTAINER=		epg@pobox.com
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Eye of GNOME: an image viewing and cataloging program

DEPENDS+=		bonobo>=1.0.18nb1:../../devel/bonobo
DEPENDS+=		GConf>=1.0.7nb1:../../devel/GConf
DEPENDS+=		gdk-pixbuf-gnome>=0.11.0nb1:../../graphics/gdk-pixbuf-gnome
DEPENDS+=		gnome-print>=0.29nb1:../../print/gnome-print
DEPENDS+=		libglade>=0.17nb1:../../devel/libglade

GNU_CONFIGURE=		YES
USE_X11BASE=		YES
USE_GMAKE=		YES
USE_LIBINTL=		YES

.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../x11/gnome-libs/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
