# $NetBSD: Makefile,v 1.17 2006/03/04 21:29:48 jlam Exp $
#

DISTNAME=	gpaint-0.2
PKGREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gpaint/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gpaint.sourceforge.net/
COMMENT=	Simple, easy-to-use paint program for GNOME

USE_DIRS+=		xdg-1.1
GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake
USE_GNU_GETTEXT=	YES
USE_X11BASE=		YES

.include "../../x11/gtk/buildlink3.mk"
.include "../../graphics/gdk-pixbuf-gnome/buildlink3.mk"
.include "../../print/gnome-print/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
