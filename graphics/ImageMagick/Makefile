# $NetBSD: Makefile,v 1.23 1998/07/15 11:10:42 agc Exp $
#

DISTNAME=	ImageMagick-4.0.6
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	tron@netbsd.org

DEPENDS+=	tiff-3.4:../../graphics/tiff
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	png-0.96:../../graphics/png
DEPENDS+=	mpeg-1.2.1:../../graphics/mpeg-lib

MIRROR_DISTFILE= no
USE_IMAKE=	yes
XMKMF=		${MAKE_ENV} xmkmf -a
MAKE_ENV=	LOCALBASE=${LOCALBASE} PREFIX=${PREFIX}

.include "../../mk/bsd.pkg.mk"
