# $NetBSD: Makefile,v 1.12 2001/06/11 06:34:36 jlam Exp $

DISTNAME=	gphoto-0.4.3
CATEGORIES=	graphics
MASTER_SITES=	http://www.gphoto.net/dist/

MAINTAINER=	jmcm@cs.cmu.edu
HOMEPAGE=	http://www.gphoto.org/
COMMENT=	Download and view files from various digital cameras

DEPENDS+=	imlib>=1.9.8:../../graphics/imlib

USE_X11BASE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
GNU_CONFIGURE=		yes
CPPFLAGS+=		-I${LOCALBASE}/include

.include "../../mk/bsd.pkg.mk"
