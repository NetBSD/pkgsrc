# $NetBSD: Makefile,v 1.23 2025/01/27 20:47:19 rillig Exp $

DISTNAME=	kttcp-20020711
PKGREVISION=	2
CATEGORIES=	benchmarks net
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Kernel network throughput benchmark

NOT_FOR_PLATFORM=	NetBSD-1.[0-5]*-* \
			NetBSD-1.6-* NetBSD-1.6.*-* NetBSD-1.6A-*
ONLY_FOR_PLATFORM=	NetBSD-*-*

USE_BSD_MAKEFILE=	yes
WRKSRC=			${WRKDIR}

INSTALLATION_DIRS=	bin

post-extract:
	cd files && cp Makefile kttcp.c ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
