# $NetBSD: Makefile,v 1.5 2002/09/30 20:54:34 skrll Exp $
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

.include "../../mk/bsd.pkg.mk"
