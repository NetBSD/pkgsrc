# $NetBSD: Makefile,v 1.5 2004/02/14 17:21:33 jlam Exp $
#

DISTNAME=	libsamplerate-0.0.13
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.mega-nerd.com/SRC/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.mega-nerd.com/SRC/
COMMENT=	Sample rate converter library

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

TEST_TARGET=	check

BUILDLINK_DEPENDS.libsndfile=	libsndfile>=1.0.2

.include "../../audio/libsndfile/buildlink2.mk"
.include "../../math/fftw2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
