# $NetBSD: Makefile,v 1.3 2001/01/07 13:30:57 taca Exp $
# FreeBSD Id: Makefile,v 1.3 1998/10/27 14:31:25 kuriyama Exp $

DISTNAME=	chasen-sys2.02-ipadic2.1
PKGNAME=	chasen-2.02
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.aist-nara.ac.jp/pub/lab/nlp/tools/chasen/ \
		http://cl.aist-nara.ac.jp/lab/nlt/chasen/package/

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://cactus.aist-nara.ac.jp/lab/nlt/chasen.html

WRKSRC=		${WRKDIR}/chasen-2.02
MAKEENV+=	LOCALBASE=\"${LOCALBASE}\"

post-build:
	${ECHO_MSG} "Making dictionaries"
	(cd ${WRKSRC}; ${MAKE} dic)

.include "../../mk/bsd.pkg.mk"
