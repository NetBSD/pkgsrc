# $NetBSD: Makefile,v 1.22 2015/01/01 09:14:31 dholland Exp $

DISTNAME=	kttcp-20020711
CATEGORIES=	benchmarks net
PKGREVISION=	2
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Kernel network throughput benchmark

ONLY_FOR_PLATFORM=	NetBSD-*-*
NOT_FOR_PLATFORM=	NetBSD-1.[0-5]*-* \
			NetBSD-1.6-* NetBSD-1.6.*-* NetBSD-1.6A-*

USE_BSD_MAKEFILE=	yes
WRKSRC=			${WRKDIR}

INSTALLATION_DIRS=	bin

post-extract:
	cd files && cp Makefile kttcp.c ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
