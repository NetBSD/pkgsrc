# $NetBSD: Makefile,v 1.3 2001/02/16 13:51:30 wiz Exp $

DISTNAME=	micq-0.4.6.p1
PKGNAME=	${DISTNAME:S/p//}
CATEGORIES=	chat
MASTER_SITES=	http://micq.ukeer.de/source/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://micq.ukeer.de/
COMMENT=	text-mode ICQ client

WRKSRC=		${WRKDIR}/${DISTNAME:S/.p/-p/}/src

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/micq ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/micq
	${INSTALL_MAN} ${WRKSRC}/../README ${PREFIX}/share/doc/micq

.include "../../mk/bsd.pkg.mk"
