# $NetBSD: Makefile,v 1.4 2002/08/07 12:07:46 agc Exp $

DISTNAME=	nProbe-source-1.3.1
PKGNAME=	nprobe-1.3.1
CATEGORIES=	net
MASTER_SITES=	http://luca.ntop.org/nprobeDownload/
EXTRACT_SUFX=	.tgz

MAINTAINER=	cjs@netbsd.org
HOMEPAGE=	http://www.ntop.org/nProbe.html
COMMENT=	Monitor a network interface and generate NetFlow data

WRKSRC=		${WRKDIR}/nProbe
GNU_CONFIGURE=	YES
USE_GMAKE=	YES
ALL_TARGET=	nprobe

INTERACTIVE_STAGE=	fetch

# Uncomment this to make a demo version of nprobe.
#CFLAGS+=	-DMAX_DEMO_FLOWS=1000 -DDEMO_MODE

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nprobe ${PREFIX}/sbin

.include "../../mk/pthread.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
