# $NetBSD: Makefile,v 1.20 1998/06/22 12:39:47 agc Exp $
#

DISTNAME=	ImageMagick-4.0.6
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	tron@netbsd.org

DEPENDS+=	tiff-3.4:../../graphics/tiff
DEPENDS+=	jpeg-6a:../../graphics/jpeg
DEPENDS+=	png-0.96:../../graphics/png
DEPENDS+=	mpeg-1.2.1:../../graphics/mpeg-lib

USE_IMAKE=	yes
XMKMF=		${MAKE_ENV} xmkmf -a
MAKE_ENV=	LOCALBASE=${LOCALBASE} PREFIX=${PREFIX}

post-install:
	${LDCONFIG} || ${TRUE}

.include "../../mk/bsd.pkg.mk"
