# $NetBSD: Makefile,v 1.10 2005/04/11 21:44:54 tv Exp $
#

DISTNAME=	libsamplerate-0.1.2
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.mega-nerd.com/SRC/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.mega-nerd.com/SRC/
COMMENT=	Sample rate converter library

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
PKGCONFIG_OVERRIDE+= ${WRKSRC}/samplerate.pc.in

TEST_TARGET=	check

BUILDLINK_DEPENDS.libsndfile+=	libsndfile>=1.0.2

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
