# $NetBSD: Makefile,v 1.5 2003/07/21 17:11:22 martti Exp $

DISTNAME=	tcpdmerge-1.0
WRKSRC=		${WRKDIR}
CATEGORIES=	net
MASTER_SITES=	http://phantom.nemoto.ecei.tohoku.ac.jp/~akiraka/tcpdmerge/
DISTFILES=	tcpdmerge.c 00README.TXT

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://phantom.nemoto.ecei.tohoku.ac.jp/~akiraka/tcpdmerge/
COMMENT=	Merge two tcpdump output files

do-extract:
	${MKDIR} ${WRKSRC}
	for i in ${DISTFILES}; do \
		${CP} ${DISTDIR}/$$i ${WRKSRC}; \
	done
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
