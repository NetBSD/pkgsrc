# $NetBSD: Makefile,v 1.18 2005/04/11 21:44:51 tv Exp $
#

DISTNAME=	amp-0.7.6
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_LOCAL}
# was ftp://ftp.rasip.fer.hr/pub/mpeg/
EXTRACT_SUFX=	.tgz

MAINTAINER=	mycroft@NetBSD.org
COMMENT=	Another mp3 player

NO_SRC_ON_FTP=	Already in MASTER_SITE_LOCAL

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	yes

INSTALLATION_DIRS=	bin man/man1

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/amp ${PREFIX}/bin
	@ ${INSTALL_MAN} ${WRKSRC}/amp.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
