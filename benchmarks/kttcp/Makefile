# $NetBSD: Makefile,v 1.9 2004/07/04 06:43:01 mrg Exp $

DISTNAME=	kttcp-${VERSION}
CATEGORIES=	benchmarks net
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	thorpej@NetBSD.org
COMMENT=	kttcp kernel network throughput benchmark

VERSION=	20020711

ONLY_FOR_PLATFORM=	NetBSD-1.6[B-Z]*-* NetBSD-1.[7-9]* NetBSD-[2-9]*

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	# defined

WRKSRC=		${WRKDIR}
MAKE_ENV+=	BINDIR=${LOCALBASE}/bin MANDIR=${LOCALBASE}/man

post-extract:
	@for FILE in Makefile kttcp.c					\
	; do								\
		${CP} ${FILESDIR}/$$FILE ${WRKSRC};			\
	done

.include "../../mk/bsd.pkg.mk"
