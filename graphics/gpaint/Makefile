# $NetBSD: Makefile,v 1.8 2004/03/08 19:40:39 jmmv Exp $
#

DISTNAME=	gpaint-0.2
PKGREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gpaint/}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://gpaint.sourceforge.net/
COMMENT=	Simple, easy-to-use paint program for GNOME

DEPENDS+=		xdg-x11-dirs>=1.1:../../misc/xdg-x11-dirs

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make
USE_GNU_GETTEXT=	YES
USE_X11BASE=		YES

.include "../../x11/gtk/buildlink2.mk"
.include "../../graphics/gdk-pixbuf-gnome/buildlink2.mk"
.include "../../print/gnome-print/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
