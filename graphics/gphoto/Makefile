# $NetBSD: Makefile,v 1.17 2003/05/02 11:55:20 wiz Exp $

DISTNAME=	gphoto-0.4.3
PKGREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://www.gphoto.net/dist/

MAINTAINER=	jmcm@cs.cmu.edu
HOMEPAGE=	http://www.gphoto.org/
COMMENT=	Download and view files from various digital cameras

DEPENDS+=	gnome1-dirs>=1.0:../../misc/gnome1-dirs

USE_BUILDLINK2=		YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
GNU_CONFIGURE=		yes
CPPFLAGS+=		-I${LOCALBASE}/include

.include "../../graphics/imlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
