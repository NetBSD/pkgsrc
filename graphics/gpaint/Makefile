# $NetBSD: Makefile,v 1.3 2003/05/02 11:55:20 wiz Exp $
#

DISTNAME=	gpaint-0.2
PKGREVISION=	2
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
