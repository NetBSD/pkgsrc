# $NetBSD: Makefile,v 1.1.1.2 2001/03/26 11:59:15 hubertf Exp $
#

DISTNAME=	p0f-1.7
CATEGORIES=	security net
MASTER_SITES=	http://lcamtuf.hack.pl/
EXTRACT_SUFX=	.tgz

MAINTAINER=	DawS@irc.pl
COMMENT=	passive OS fingerprinting tool

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/p0f ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/p0f.fp ${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/p0f.README

.include "../../mk/bsd.pkg.mk"
