# $NetBSD: Makefile,v 1.8 1999/12/25 18:03:23 wiz Exp $
#

DISTNAME=	amp-0.7.6
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_LOCAL}
# was ftp://ftp.rasip.fer.hr/pub/mpeg/
EXTRACT_SUFX=	.tgz

MAINTAINER=	mycroft@netbsd.org

MIRROR_DISTFILE=	no
GNU_CONFIGURE=	yes

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/amp ${PREFIX}/bin
	@ ${INSTALL_MAN} ${WRKSRC}/amp.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
