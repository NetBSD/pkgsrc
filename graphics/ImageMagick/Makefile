# $NetBSD: Makefile,v 1.26 1998/08/13 07:31:37 tron Exp $
#

DISTNAME=	ImageMagick-4.0.8
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	tron@netbsd.org

DEPENDS+=	tiff-3.4:../../graphics/tiff
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	png-1.0.2:../../graphics/png
DEPENDS+=	mpeg-1.2.1:../../graphics/mpeg-lib

CONFLICTS=	ImageMagick-4.0 ImageMagick-4.0.1 ImageMagick-4.0.3 \
		ImageMagick-4.0.5 ImageMagick-4.0.6 ImageMagick-4.0.7

MIRROR_DISTFILE= no
USE_IMAKE=	yes
XMKMF=		${MAKE_ENV} xmkmf -a
MAKE_ENV=	LOCALBASE=${LOCALBASE} PREFIX=${PREFIX}

.include "../../mk/bsd.pkg.mk"
