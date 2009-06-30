# $NetBSD: Makefile,v 1.29 2009/06/30 00:07:17 joerg Exp $

DISTNAME=	gphoto-0.4.3
PKGREVISION=	9
CATEGORIES=	graphics
#MASTER_SITES=	http://www.gphoto.net/dist/

MAINTAINER=	jmcm@cs.cmu.edu
HOMEPAGE=	http://www.gphoto.org/
COMMENT=	Download and view files from various digital cameras

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

USE_DIRS+=		gnome1-1.0
USE_X11BASE=		YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		yes

.include "../../graphics/imlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
