# $NetBSD: Makefile,v 1.1.1.1 2000/12/15 00:36:29 wiz Exp $
#

DISTNAME=	micq-0.4.6
CATEGORIES=	chat
MASTER_SITES=	ftp://micq.chatzone.org/pub/${DISTNAME:S/-/\/V/}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://micq.maesoft.net/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/micq ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/micq
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/micq

.include "../../mk/bsd.pkg.mk"
