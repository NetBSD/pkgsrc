# $NetBSD: Makefile,v 1.1.1.1 2003/04/06 11:08:14 rh Exp $
#

DISTNAME=		gxine-0.3.2
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xine/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://xinehq.de/
COMMENT=		gtk-based media player

USE_BUILDLINK2=		YES
USE_X11=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		YES

.include "../../graphics/xine-lib/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
