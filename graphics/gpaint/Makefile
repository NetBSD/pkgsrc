# $NetBSD: Makefile,v 1.1.1.1 2002/12/19 12:27:32 grant Exp $
#

DISTNAME=	gpaint-0.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gpaint/}

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://gpaint.sourceforge.net/
COMMENT=	Simple, easy-to-use paint program for GNOME

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_GMAKE=		YES
USE_GNU_GETTEXT=	YES
USE_X11BASE=		YES

.include "../../x11/gtk/buildlink2.mk"
.include "../../graphics/gdk-pixbuf-gnome/buildlink2.mk"
.include "../../print/gnome-print/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
