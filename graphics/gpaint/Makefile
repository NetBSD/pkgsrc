# $NetBSD: Makefile,v 1.11 2004/04/25 01:52:25 snj Exp $
#

DISTNAME=	gpaint-0.2
PKGREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gpaint/}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://gpaint.sourceforge.net/
COMMENT=	Simple, easy-to-use paint program for GNOME

USE_BUILDLINK3=		YES
USE_DIRS+=		xdg-1.1
GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make
USE_GNU_GETTEXT=	YES
USE_X11BASE=		YES

.include "../../x11/gtk/buildlink3.mk"
.include "../../graphics/gdk-pixbuf-gnome/buildlink3.mk"
.include "../../print/gnome-print/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
