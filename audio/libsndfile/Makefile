# $NetBSD: Makefile,v 1.4 2002/09/28 11:35:51 wiz Exp $
#

DISTNAME=	libsndfile-1.0.1
CATEGORIES=	audio
MASTER_SITES=	http://www.zipworld.com.au/~erikd/libsndfile/

MAINTAINER=	dillo@giga.or.at
HOMEPAGE=	http://www.zipworld.com.au/~erikd/libsndfile/
COMMENT=	library for reading and writing audio files

USE_LIBTOOL=	YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES

# needs libm for fmod(3), but somehow it does not end up in
# libtool's .la file
LIBS+=	-lm

.include "../../mk/bsd.pkg.mk"
