# $NetBSD: Makefile,v 1.21 2004/04/25 01:58:44 snj Exp $

DISTNAME=	gphoto-0.4.3
PKGREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	http://www.gphoto.net/dist/

MAINTAINER=	jmcm@cs.cmu.edu
HOMEPAGE=	http://www.gphoto.org/
COMMENT=	Download and view files from various digital cameras

USE_BUILDLINK3=		YES
USE_DIRS+=		gnome1-1.0
USE_X11BASE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
GNU_CONFIGURE=		yes

.include "../../graphics/imlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
