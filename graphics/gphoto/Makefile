# $NetBSD: Makefile,v 1.13 2002/03/13 17:37:08 fredb Exp $

DISTNAME=	gphoto-0.4.3
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.gphoto.net/dist/

MAINTAINER=	jmcm@cs.cmu.edu
HOMEPAGE=	http://www.gphoto.org/
COMMENT=	Download and view files from various digital cameras

DEPENDS+=	imlib>=1.9.11nb1:../../graphics/imlib

USE_X11BASE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
GNU_CONFIGURE=		yes
CPPFLAGS+=		-I${LOCALBASE}/include

.include "../../mk/bsd.pkg.mk"
