# $NetBSD: Makefile,v 1.5 2003/03/29 12:40:12 jmmv Exp $

DISTNAME=	kttcp-${VERSION}
WRKSRC=		${WRKDIR}
CATEGORIES=	benchmarks net
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	thorpej@netbsd.org
COMMENT=	kttcp kernel network throughput benchmark

VERSION=	20020711

ONLY_FOR_PLATFORM=	NetBSD-1.6[B-Z]-*

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	# defined

MAKE_ENV+=	BINDIR=${LOCALBASE}/bin MANDIR=${LOCALBASE}/man

post-extract:
	@for FILE in Makefile kttcp.c					\
	; do								\
		${CP} ${FILESDIR}/$$FILE ${WRKSRC};			\
	done

.include "../../mk/bsd.pkg.mk"
