# $NetBSD: Makefile,v 1.1.1.1 2002/08/23 11:39:27 dillo Exp $
#

DISTNAME=	libsndfile-1.0.0
CATEGORIES=	audio
MASTER_SITES=	http://www.zipworld.com.au/~erikd/libsndfile/

MAINTAINER=	dillo@giga.or.at
HOMEPAGE=	http://www.zipworld.com.au/~erikd/libsndfile/
COMMENT=	library for reading and writing audio files

USE_LIBTOOL=	YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
GNU_CONFIGURE=	YES
USE_BUILDLINK_ONLY=YES

.include "../../mk/bsd.pkg.mk"
