# $NetBSD: Makefile,v 1.2 1999/06/07 09:54:39 sakamoto Exp $
# FreeBSD Id: Makefile,v 1.3 1998/10/27 14:31:25 kuriyama Exp $

DISTNAME=	chasen-sys2.0b6-ipadic1.0
PKGNAME=	chasen-2.0b6
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.aist-nara.ac.jp/pub/lab/nlp/tools/chasen/ \
		http://cactus.aist-nara.ac.jp/~akira-k/cha/arc/

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://cactus.aist-nara.ac.jp/lab/nlt/chasen.html

WRKSRC=		${WRKDIR}/chasen-2.0b6

post-build:
	${ECHO_MSG} "Making dictionaries"
	(cd ${WRKSRC}; ${MAKE} dic)

.include "../../mk/bsd.pkg.mk"
