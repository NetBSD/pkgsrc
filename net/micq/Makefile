# $NetBSD: Makefile,v 1.1.1.1 2000/02/06 01:10:25 wiz Exp $
#

DISTNAME=	micq-0.4.3
CATEGORIES=	net
MASTER_SITES=	ftp://micq.chatzone.org/pub/micq/V0.4.3/ \
		http://micq.maesoft.net/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://micq.maesoft.net/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/micq ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/micq
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/micq

.include "../../mk/bsd.pkg.mk"
