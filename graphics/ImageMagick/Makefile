# New ports collection Makefile for: ImageMagick
# Version required:	4.0
# Date created:         11th December 1997
# Whom:                 tron
#
# $NetBSD: Makefile,v 1.10 1998/02/02 08:59:13 hubertf Exp $
#

DISTNAME=	ImageMagick-4.0
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.wizards.dupont.com/pub/ImageMagick/ \
		ftp://ftp.ms.mff.cuni.cz/MIRRORS/ftp.wizards.dupont.com/pub/ImageMagick/ \
		ftp://ftp.oce.nl/pub/Internet/audio+video/ImageMagick/

MAINTAINER=	tron@netbsd.org

LIB_DEPENDS=    jpeg.7.:${PORTSDIR}/graphics/jpeg \
		mpeg.1.2:${PORTSDIR}/graphics/mpeg-lib \
		png.0.:${PORTSDIR}/graphics/png \
		tiff.3.4:${PORTSDIR}/graphics/tiff

USE_IMAKE=	yes
XMKMF=		${MAKE_ENV} xmkmf -a
MAKE_ENV=	LOCALBASE=${LOCALBASE} PREFIX=${PREFIX}

NO_CHECKSUM=	yes

CAT1=		display.0 montage.0 import.0 animate.0 convert.0 identify.0 \
		mogrify.0 combine.0 ImageMagick.0 xtp.0

CAT4=		miff.0
CAT5=		quantize.0

post-extract:
	(cd ${WRKSRC} && \
	    for i in display montage import animate convert identify \
		mogrify combine ImageMagick; do \
	        ln -s $$i.1 $$i.man ; \
	    done; \
	    ln -s miff.4 miff.man; \
	    ln -s quantize.5 quantize.man; )
	(cd ${WRKSRC}/xtp && ln -s xtp.1 xtp.man)


post-install:
	${LDCONFIG} || ${TRUE}

.include <bsd.port.mk>
