# $NetBSD: Makefile,v 1.1.1.1 2002/12/14 18:23:16 jmmv Exp $
#

DISTNAME=	libsamplerate-0.0.13
CATEGORIES=	audio
MASTER_SITES=	http://www.mega-nerd.com/SRC/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.mega-nerd.com/SRC/
COMMENT=	Sample rate converter library

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

BUILDLINK_DEPENDS.libsndfile=	libsndfile>=1.0.2

.include "../../audio/libsndfile/buildlink2.mk"
.include "../../math/fftw/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
