# $NetBSD: Makefile,v 1.2 2002/05/05 16:10:26 wiz Exp $

DISTNAME=	musicbrainz-1.1.0
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.musicbrainz.org/pub/musicbrainz/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://www.musicbrainz.org/
COMMENT=	second generation incarnation of the CD Index

USE_GMAKE=	YES
GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltmain.sh

post-configure:
	# this pkg generates libtool script from configure file
	cd ${WRKSRC} && ./ltmain.sh

.include "../../mk/bsd.pkg.mk"
