# $NetBSD: Makefile,v 1.2 2004/02/14 17:21:45 jlam Exp $
#

DISTNAME=		gxine-0.3.3
PKGREVISION=		5
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
