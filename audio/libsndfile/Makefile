# $NetBSD: Makefile,v 1.6 2002/10/18 13:26:12 jlam Exp $
#

DISTNAME=	libsndfile-1.0.1
CATEGORIES=	audio
MASTER_SITES=	http://www.zipworld.com.au/~erikd/libsndfile/

MAINTAINER=	dillo@giga.or.at
HOMEPAGE=	http://www.zipworld.com.au/~erikd/libsndfile/
COMMENT=	library for reading and writing audio files

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.prefs.mk"

.if defined(USE_OSS)
.  include "../../mk/ossaudio.buildlink2.mk"
OSS_DEFS=		-DDEV_DSP=\\\"${DEVOSSAUDIO}\\\" -DUSE_OSS=1
MAKE_ENV+=		AM_CFLAGS="${OSS_DEFS}"
.endif

.include "../../mk/bsd.pkg.mk"
