# $NetBSD: Makefile,v 1.12 2002/08/28 08:38:01 jlam Exp $
#

DISTNAME=	amp-0.7.6
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_LOCAL}
# was ftp://ftp.rasip.fer.hr/pub/mpeg/
EXTRACT_SUFX=	.tgz

MAINTAINER=	mycroft@netbsd.org
COMMENT=	another mp3 player

NO_SRC_ON_FTP=	Already in MASTER_SITE_LOCAL

USE_BUILDLINK2=	yes
GNU_CONFIGURE=	yes

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/amp ${PREFIX}/bin
	@ ${INSTALL_MAN} ${WRKSRC}/amp.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
