# $NetBSD: Makefile,v 1.19 2004/10/03 00:14:50 tv Exp $

DISTNAME=		eog-0.6
PKGREVISION=		8
CATEGORIES=		gnome graphics x11
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/eog/0.6/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Eye of GNOME: an image viewing and cataloging program

GNU_CONFIGURE=		YES
USE_X11BASE=		YES
USE_GNU_TOOLS+=		make
USE_BUILDLINK3=		YES
USE_DIRS+=		xdg-1.1
USE_PKGLOCALEDIR=	YES

.include "../../devel/bonobo/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../graphics/gdk-pixbuf-gnome/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../print/gnome-print/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
