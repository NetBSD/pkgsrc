# New ports collection Makefile for: ImageMagick
# Version required:	3.9.3
# Date created:         11th December 1997
# Whom:                 tron
#
# $NetBSD: Makefile,v 1.4 1998/01/24 20:15:23 hubertf Exp $
#

DISTNAME=	ImageMagick-3.9.3
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.wizards.dupont.com/pub/ImageMagick/ \
		ftp://ftp.ms.mff.cuni.cz/MIRRORS/ftp.wizards.dupont.com/pub/ImageMagick/ \
		ftp://ftp.oce.nl/pub/Internet/audio+video/ImageMagick/

MAINTAINER=	packages@netbsd.org

LIB_DEPENDS=    jpeg\\.7\\.:${PORTSDIR}/graphics/jpeg \
		mpeg\\.1\\.2:${PORTSDIR}/graphics/mpeg-lib \
		png\\.0\\.96:${PORTSDIR}/graphics/png \
		tiff\\.3\\.4:${PORTSDIR}/graphics/tiff

USE_IMAKE=	yes
WRKSRC=		${WRKDIR}/ImageMagick
MAKE_ENV=	LOCALBASE=${LOCALBASE} PREFIX=${PREFIX}

NO_CHECKSUM=	yes

CAT1=		display.0 montage.0 import.0 animate.0 convert.0 identify.0 \
		mogrify.0 combine.0 ImageMagick.0 quantize.0 miff.0 xtp.0

post-install:
	${LDCONFIG} -m ${PREFIX}/lib || /usr/bin/true

.include <bsd.port.mk>
