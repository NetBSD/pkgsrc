# $NetBSD: Makefile,v 1.15 2004/03/08 19:40:39 jmmv Exp $

DISTNAME=		eog-0.6
PKGREVISION=		7
CATEGORIES=		gnome graphics x11
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/eog/0.6/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Eye of GNOME: an image viewing and cataloging program

DEPENDS+=		xdg-x11-dirs>=1.1:../../misc/xdg-x11-dirs

GNU_CONFIGURE=		YES
USE_X11BASE=		YES
USE_GNU_TOOLS+=		make
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
