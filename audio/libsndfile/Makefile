# $NetBSD: Makefile,v 1.2 2002/08/31 14:11:45 wiz Exp $
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
USE_BUILDLINK2=	YES

.include "../../mk/bsd.pkg.mk"
