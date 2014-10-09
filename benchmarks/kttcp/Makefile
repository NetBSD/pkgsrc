# $NetBSD: Makefile,v 1.21 2014/10/09 14:05:59 wiz Exp $

DISTNAME=	kttcp-20020711
CATEGORIES=	benchmarks net
PKGREVISION=	2
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Kernel network throughput benchmark

ONLY_FOR_PLATFORM=	NetBSD-1.6[B-Z]*-* NetBSD-[2-9]*-*

USE_BSD_MAKEFILE=	yes
WRKSRC=			${WRKDIR}

INSTALLATION_DIRS=	bin

post-extract:
	cd files && cp Makefile kttcp.c ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
