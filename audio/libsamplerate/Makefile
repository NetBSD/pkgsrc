# $NetBSD: Makefile,v 1.4 2003/07/17 21:22:43 grant Exp $
#

DISTNAME=	libsamplerate-0.0.13
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.mega-nerd.com/SRC/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.mega-nerd.com/SRC/
COMMENT=	Sample rate converter library

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

TEST_TARGET=	check

BUILDLINK_DEPENDS.libsndfile=	libsndfile>=1.0.2

.include "../../audio/libsndfile/buildlink2.mk"
.include "../../math/fftw2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
