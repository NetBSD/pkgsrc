# $NetBSD: Makefile,v 1.17 1998/04/15 22:21:17 tron Exp $
#

DISTNAME=	ImageMagick-4.0.5
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	tron@netbsd.org

LIB_DEPENDS=    jpeg.7.:${PORTSDIR}/graphics/jpeg \
		mpeg.1.2:${PORTSDIR}/graphics/mpeg-lib \
		png.0.:${PORTSDIR}/graphics/png \
		tiff.3.4:${PORTSDIR}/graphics/tiff

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
