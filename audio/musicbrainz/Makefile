# $NetBSD: Makefile,v 1.1.1.1 2002/04/19 20:23:58 zuntum Exp $

DISTNAME=	musicbrainz-1.1.0
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.musicbrainz.org/pub/musicbrainz/

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
