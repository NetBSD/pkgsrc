# $NetBSD: Makefile,v 1.3 2003/06/02 01:17:43 jschauma Exp $

DISTNAME=	tcpdmerge-1.0
WRKSRC=		${WRKDIR}
CATEGORIES=	net
MASTER_SITES=	http://phantom.nemoto.ecei.tohoku.ac.jp/~akiraka/tcpdmerge/
DISTFILES=	tcpdmerge.c 00README.TXT

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://phantom.nemoto.ecei.tohoku.ac.jp/~akiraka/tcpdmerge/
COMMENT=	merge two tcpdump output files

do-extract:
	${MKDIR} ${WRKSRC}
	for i in ${DISTFILES}; do \
		${CP} ${DISTDIR}/$$i ${WRKSRC}; \
	done
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
