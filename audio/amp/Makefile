# $NetBSD: Makefile,v 1.9 2000/08/18 22:46:30 hubertf Exp $
#

DISTNAME=	amp-0.7.6
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_LOCAL}
# was ftp://ftp.rasip.fer.hr/pub/mpeg/
EXTRACT_SUFX=	.tgz

MAINTAINER=	mycroft@netbsd.org

NO_SRC_ON_FTP=	Already in MASTER_SITE_LOCAL

GNU_CONFIGURE=	yes

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/amp ${PREFIX}/bin
	@ ${INSTALL_MAN} ${WRKSRC}/amp.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
