# $NetBSD: Makefile,v 1.7 1998/08/26 16:50:48 tsarna Exp $
#

DISTNAME=	amp-0.7.6
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.rasip.fer.hr/pub/mpeg/
EXTRACT_SUFX=	.tgz

MAINTAINER=	mycroft@netbsd.org

GNU_CONFIGURE=	yes

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/amp ${PREFIX}/bin
	@ ${INSTALL_MAN} ${WRKSRC}/amp.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
