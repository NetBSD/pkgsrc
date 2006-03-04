# $NetBSD: Makefile,v 1.8 2006/03/04 21:30:24 jlam Exp $

DISTNAME=	tcpdmerge-1.0
CATEGORIES=	net
MASTER_SITES=	http://phantom.nemoto.ecei.tohoku.ac.jp/~akiraka/tcpdmerge/
DISTFILES=	tcpdmerge.c 00README.TXT

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://phantom.nemoto.ecei.tohoku.ac.jp/~akiraka/tcpdmerge/
COMMENT=	Merge two tcpdump output files

WRKSRC=		${WRKDIR}

do-extract:
	${MKDIR} ${WRKSRC}
	for i in ${DISTFILES}; do \
		${CP} ${DISTDIR}/$$i ${WRKSRC}; \
	done
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
