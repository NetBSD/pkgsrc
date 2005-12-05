# $NetBSD: Makefile,v 1.13 2005/12/05 20:49:51 rillig Exp $

DISTNAME=	kttcp-${VERSION}
CATEGORIES=	benchmarks net
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	thorpej@NetBSD.org
COMMENT=	Kernel network throughput benchmark

VERSION=	20020711

ONLY_FOR_PLATFORM=	NetBSD-1.6[B-Z]*-* NetBSD-[2-9]*-*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes

WRKSRC=		${WRKDIR}
MAKE_ENV+=	BINDIR=${LOCALBASE}/bin MANDIR=${LOCALBASE}/man

INSTALLATION_DIRS=	bin

post-extract:
	@for FILE in Makefile kttcp.c					\
	; do								\
		${CP} ${FILESDIR}/$$FILE ${WRKSRC};			\
	done

.include "../../mk/bsd.pkg.mk"
