# $NetBSD: Makefile,v 1.12 2006/03/04 21:28:56 jlam Exp $
#

DISTNAME=	libsamplerate-0.1.2
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.mega-nerd.com/SRC/

MAINTAINER=	pkgsrc-users@NetBSD.org
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
