# $NetBSD: Makefile,v 1.27 2006/07/19 19:14:38 jlam Exp $

DISTNAME=	gphoto-0.4.3
PKGREVISION=	9
CATEGORIES=	graphics
#MASTER_SITES=	http://www.gphoto.net/dist/

MAINTAINER=	jmcm@cs.cmu.edu
HOMEPAGE=	http://www.gphoto.org/
COMMENT=	Download and view files from various digital cameras

USE_DIRS+=		gnome1-1.0
USE_X11BASE=		YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		yes

.include "../../graphics/imlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
