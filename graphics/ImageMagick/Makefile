# New ports collection Makefile for: ImageMagick
# Version required:	4.0.1
# Date created:         09th February 1998
# Whom:                 tron
#
# $NetBSD: Makefile,v 1.15 1998/03/28 21:55:48 tron Exp $
#

DISTNAME=	ImageMagick-4.0.3
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

.include <bsd.port.mk>
