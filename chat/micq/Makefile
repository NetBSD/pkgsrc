# $NetBSD: Makefile,v 1.4 2001/03/18 15:59:13 itojun Exp $

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
	${INSTALL_MAN} ${WRKSRC}/../micq.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
