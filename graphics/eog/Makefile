# $NetBSD: Makefile,v 1.3 2002/10/06 14:06:42 wiz Exp $

DISTNAME=		eog-0.6
PKGREVISION=		1
CATEGORIES=		gnome graphics x11
MASTER_SITES=		${MASTER_SITE_GNOME:=unstable/sources/eog/}

MAINTAINER=		epg@pobox.com
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Eye of GNOME: an image viewing and cataloging program

GNU_CONFIGURE=		YES
USE_X11BASE=		YES
USE_GMAKE=		YES
USE_LIBINTL=		YES
USE_BUILDLINK2=		YES

.include "../../devel/bonobo/buildlink2.mk"
.include "../../devel/GConf/buildlink2.mk"
.include "../../devel/libglade/buildlink2.mk"
.include "../../graphics/gdk-pixbuf-gnome/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../print/gnome-print/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
