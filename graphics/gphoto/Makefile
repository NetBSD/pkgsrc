# $NetBSD: Makefile,v 1.15 2003/01/28 23:00:54 jmmv Exp $

DISTNAME=	gphoto-0.4.3
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://www.gphoto.net/dist/

MAINTAINER=	jmcm@cs.cmu.edu
HOMEPAGE=	http://www.gphoto.org/
COMMENT=	Download and view files from various digital cameras

USE_BUILDLINK2=		YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
GNU_CONFIGURE=		yes
CPPFLAGS+=		-I${LOCALBASE}/include

.include "../../graphics/imlib/buildlink2.mk"
.include "../../misc/gnome1-dirs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
