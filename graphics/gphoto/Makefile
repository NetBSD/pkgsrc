# $NetBSD: Makefile,v 1.35 2011/02/19 09:02:06 markd Exp $

DISTNAME=	gphoto-0.4.3
PKGREVISION=	14
CATEGORIES=	graphics
#MASTER_SITES=	http://www.gphoto.net/dist/

MAINTAINER=	jmcm@cs.cmu.edu
HOMEPAGE=	http://www.gphoto.org/
COMMENT=	Download and view files from various digital cameras

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

USE_X11BASE=		YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		yes

.include "../../graphics/imlib-gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
