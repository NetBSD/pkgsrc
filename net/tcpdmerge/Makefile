# $NetBSD: Makefile,v 1.6 2004/01/20 12:22:22 agc Exp $

DISTNAME=	tcpdmerge-1.0
CATEGORIES=	net
MASTER_SITES=	http://phantom.nemoto.ecei.tohoku.ac.jp/~akiraka/tcpdmerge/
DISTFILES=	tcpdmerge.c 00README.TXT

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://phantom.nemoto.ecei.tohoku.ac.jp/~akiraka/tcpdmerge/
COMMENT=	Merge two tcpdump output files

WRKSRC=		${WRKDIR}

do-extract:
	${MKDIR} ${WRKSRC}
	for i in ${DISTFILES}; do \
		${CP} ${DISTDIR}/$$i ${WRKSRC}; \
	done
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
