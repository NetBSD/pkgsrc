# $NetBSD: Makefile,v 1.23 2012/09/11 23:59:24 asau Exp $
#

DISTNAME=	amp-0.7.6
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_LOCAL}
# was ftp://ftp.rasip.fer.hr/pub/mpeg/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Another mp3 player

NO_SRC_ON_FTP=	Already in MASTER_SITE_LOCAL

NOT_FOR_PLATFORM=	Interix-*-*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/amp ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/amp.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
