# $NetBSD: Makefile,v 1.8 2003/07/21 16:51:37 martti Exp $
# FreeBSD Id: Makefile,v 1.10 1998/01/17 17:46:00 itojun Exp
#

DISTNAME=	camediaplay-20010211
WRKSRC=		${WRKDIR}/camediaplay/build
CATEGORIES=	graphics
MASTER_SITES=   ftp://ftp.itojun.org/pub/digi-cam/C-400L/unix/ \
		ftp://ftp.digipri.co.jp/pub/free-software/Olympus/C-400L/unix/

MAINTAINER=	hubertf@NetBSD.org
COMMENT=	Digital camera downloading tool for Epson/Sanyo/Olympus/Agfa camera

GNU_CONFIGURE=	yes

DOC=	README.english README.japanese PROTOCOL

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/camediaplay
	for i in ${DOC}; do \
		${INSTALL_DATA} ${WRKSRC}/../$$i \
			${PREFIX}/share/doc/camediaplay; \
	done

.include "../../mk/bsd.pkg.mk"
