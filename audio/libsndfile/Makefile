# $NetBSD: Makefile,v 1.10 2003/07/21 16:30:42 martti Exp $
#

DISTNAME=	libsndfile-1.0.5
CATEGORIES=	audio
MASTER_SITES=	http://www.zipworld.com.au/~erikd/libsndfile/

MAINTAINER=	dillo@giga.or.at
HOMEPAGE=	http://www.zipworld.com.au/~erikd/libsndfile/
COMMENT=	Library for reading and writing audio files

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../mk/bsd.prefs.mk"

.if defined(USE_OSS)
.  include "../../mk/ossaudio.buildlink2.mk"
OSS_DEFS=		-DDEV_DSP=\\\"${DEVOSSAUDIO}\\\" -DUSE_OSS=1
MAKE_ENV+=		AM_CFLAGS="${OSS_DEFS}"
.endif

.include "../../mk/bsd.pkg.mk"
