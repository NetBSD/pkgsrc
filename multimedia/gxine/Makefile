# $NetBSD: Makefile,v 1.7 2005/01/06 17:22:52 drochner Exp $
#

DISTNAME=		gxine-0.4.1
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xine/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://xinehq.de/
COMMENT=		Gtk-based media player

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
USE_X11=		YES

.include "../../devel/glib2/buildlink3.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
