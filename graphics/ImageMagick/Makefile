# $NetBSD: Makefile,v 1.18 1998/04/22 14:22:41 agc Exp $
#

DISTNAME=	ImageMagick-4.0.5
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

CAT1=		display.0 montage.0 import.0 animate.0 convert.0 identify.0 \
		mogrify.0 combine.0 ImageMagick.0 xtp.0

CAT4=		miff.0
CAT5=		quantize.0

post-install:
	${LDCONFIG} || ${TRUE}

.include "../../mk/bsd.pkg.mk"
