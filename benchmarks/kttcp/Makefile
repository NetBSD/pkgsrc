# $NetBSD: Makefile,v 1.1.1.1 2002/06/29 01:07:19 thorpej Exp $

DISTNAME=	kttcp-${VERSION}
CATEGORIES=	benchmarks net
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	thorpej@netbsd.org
COMMENT=	kttcp kernel network throughput benchmark

VERSION=	20020628

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
