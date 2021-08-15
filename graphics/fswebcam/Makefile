# $NetBSD: Makefile,v 1.1 2021/08/15 06:57:48 nia Exp $

DISTNAME=	fswebcam-20200725
CATEGORIES=	graphics
MASTER_SITES=	https://www.sanslogic.co.uk/fswebcam/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.sanslogic.co.uk/fswebcam/
COMMENT=	Simple app to capture images from a webcam
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes

MANCOMPRESSED=	yes

CONFIGURE_ARGS+=	--disable-v4l1

pre-configure:
.if exists(/usr/include/sys/videoio.h)
	${CP} /usr/include/sys/videoio.h ${WRKSRC}/videodev2.h
.endif

.include "../../graphics/gd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
