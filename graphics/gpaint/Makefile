# $NetBSD: Makefile,v 1.9 2004/04/14 16:15:24 jmmv Exp $
#

DISTNAME=	gpaint-0.2
PKGREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gpaint/}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://gpaint.sourceforge.net/
COMMENT=	Simple, easy-to-use paint program for GNOME

USE_BUILDLINK2=		YES
USE_DIRS+=		xdg-x11-1.1
GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make
USE_GNU_GETTEXT=	YES
USE_X11BASE=		YES

.include "../../x11/gtk/buildlink2.mk"
.include "../../graphics/gdk-pixbuf-gnome/buildlink2.mk"
.include "../../print/gnome-print/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
