# $NetBSD: Makefile,v 1.11 2003/11/12 01:31:49 salo Exp $

DISTNAME=		eog-0.6
PKGREVISION=		5
CATEGORIES=		gnome graphics x11
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/eog/0.6/}

MAINTAINER=		epg@pobox.com
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Eye of GNOME: an image viewing and cataloging program

GNU_CONFIGURE=		YES
USE_X11BASE=		YES
USE_GMAKE=		YES
USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES

.include "../../devel/bonobo/buildlink2.mk"
.include "../../devel/GConf/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libglade/buildlink2.mk"
.include "../../graphics/gdk-pixbuf-gnome/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../print/gnome-print/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
