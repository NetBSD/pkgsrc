# $NetBSD: Makefile,v 1.20 2004/04/14 16:15:24 jmmv Exp $

DISTNAME=	gphoto-0.4.3
PKGREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	http://www.gphoto.net/dist/

MAINTAINER=	jmcm@cs.cmu.edu
HOMEPAGE=	http://www.gphoto.org/
COMMENT=	Download and view files from various digital cameras

USE_BUILDLINK2=		YES
USE_DIRS+=		gnome1-1.0
USE_X11BASE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
GNU_CONFIGURE=		yes
CPPFLAGS+=		-I${LOCALBASE}/include

.include "../../graphics/imlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
