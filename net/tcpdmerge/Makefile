# $NetBSD: Makefile,v 1.1.1.1 2001/03/06 02:58:39 itojun Exp $

DISTNAME=	tcpdmerge-1.0
CATEGORIES=	net
MASTER_SITES=	http://phantom.nemoto.ecei.tohoku.ac.jp/~akiraka/tcpdmerge/
DISTFILES=	tcpdmerge.c 00README.TXT

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://phantom.nemoto.ecei.tohoku.ac.jp/~akiraka/tcpdmerge/
COMMENT=	merge two tcpdump output files

WRKSRC=	${WRKDIR}

do-extract:
	${MKDIR} ${WRKSRC}
	for i in ${DISTFILES}; do \
		${CP} ${DISTDIR}/$$i ${WRKSRC}; \
	done
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
