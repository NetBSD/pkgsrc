# $NetBSD: Makefile,v 1.3 2003/05/02 11:55:21 wiz Exp $
#

DISTNAME=		gxine-0.3.3
PKGREVISION=	1
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

.include "../../devel/glib2/buildlink2.mk"
.include "../../graphics/xine-lib/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
