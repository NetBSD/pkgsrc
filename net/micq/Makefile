# $NetBSD: Makefile,v 1.2 2000/06/16 12:00:57 tron Exp $
#

DISTNAME=	micq-0.4.6
CATEGORIES=	net
MASTER_SITES=	ftp://micq.chatzone.org/pub/${DISTNAME:S/-/\/V/}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://micq.maesoft.net/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/micq ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/micq
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/micq

.include "../../mk/bsd.pkg.mk"
