# $NetBSD: Makefile,v 1.2 2002/06/29 01:10:34 thorpej Exp $

DISTNAME=	kttcp-${VERSION}
CATEGORIES=	benchmarks net
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	thorpej@netbsd.org
COMMENT=	kttcp kernel network throughput benchmark

VERSION=	20020628

ONLY_FOR_PLATFORM=	NetBSD-*-*

EXTRACT_ONLY=	# empty
WRKSRC=		${WRKDIR}
NO_CHECKSUM=	# defined

MAKE_ENV+=	BINDIR=${LOCALBASE}/bin MANDIR=${LOCALBASE}/man

post-extract:
	@for FILE in Makefile kttcp.c					\
	; do								\
		${CP} ${FILESDIR}/$$FILE ${WRKSRC};			\
	done

.include "../../mk/bsd.pkg.mk"
