# $NetBSD: Makefile,v 1.4 2004/03/29 03:43:51 snj Exp $
#

DISTNAME=		gxine-0.3.3
PKGREVISION=		6
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
