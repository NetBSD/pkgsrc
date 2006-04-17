# $NetBSD: Makefile,v 1.18 2006/04/17 13:46:32 wiz Exp $
#

DISTNAME=	gpaint-0.2
PKGREVISION=	8
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
