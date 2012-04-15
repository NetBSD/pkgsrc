# $NetBSD: Makefile,v 1.19 2012/04/15 22:00:58 wiz Exp $

DISTNAME=	kttcp-20020711
CATEGORIES=	benchmarks net
PKGREVISION=	2
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Kernel network throughput benchmark

ONLY_FOR_PLATFORM=	NetBSD-1.6[B-Z]*-* NetBSD-[2-9]*-*

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_BSD_MAKEFILE=	yes
WRKSRC=			${WRKDIR}

INSTALLATION_DIRS=	bin

post-extract:
	cd files && cp Makefile kttcp.c ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
