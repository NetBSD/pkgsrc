# $NetBSD: Makefile,v 1.19 2004/04/24 23:04:28 wiz Exp $
#

DISTNAME=	libsndfile-1.0.9
CATEGORIES=	audio
MASTER_SITES=	http://www.mega-nerd.com/libsndfile/

MAINTAINER=	dillo@giga.or.at
HOMEPAGE=	http://www.mega-nerd.com/libsndfile/
COMMENT=	Library for reading and writing audio files

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
PKGCONFIG_OVERRIDE=	sndfile.pc.in

# This package needs a C99 compiler
GCC_REQD+=		3.1

.include "../../mk/bsd.prefs.mk"

.if defined(USE_OSS)
.  include "../../mk/ossaudio.buildlink3.mk"
OSS_DEFS=		-DDEV_DSP=\\\"${DEVOSSAUDIO}\\\" -DUSE_OSS=1
MAKE_ENV+=		AM_CFLAGS="${OSS_DEFS}"
.endif

.include "../../mk/bsd.pkg.mk"
