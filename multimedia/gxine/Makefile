# $NetBSD: Makefile,v 1.3 2004/03/11 17:27:29 jmmv Exp $
#

DISTNAME=		gxine-0.3.3
PKGREVISION=		6
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xine/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://xinehq.de/
COMMENT=		Gtk-based media player

USE_BUILDLINK2=		YES
USE_X11=		YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

.include "../../devel/glib2/buildlink2.mk"
.include "../../multimedia/xine-lib/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
