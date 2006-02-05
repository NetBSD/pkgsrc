# $NetBSD: Makefile,v 1.17 2006/02/05 23:10:28 joerg Exp $

DISTNAME=	nProbe-source-1.3.1
PKGREVISION=	3
PKGNAME=	nprobe-1.3.1
CATEGORIES=	net
MASTER_SITES=	http://luca.ntop.org/nprobeDownload/
EXTRACT_SUFX=	.tgz

MAINTAINER=	cjs@NetBSD.org
HOMEPAGE=	http://www.ntop.org/nProbe.html
COMMENT=	Monitor a network interface and generate NetFlow data

WRKSRC=		${WRKDIR}/nProbe
GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake
BUILD_TARGET=	nprobe

INTERACTIVE_STAGE=	fetch
INSTALLATION_DIRS=	sbin

# Uncomment this to make a demo version of nprobe.
#CFLAGS+=	-DMAX_DEMO_FLOWS=1000 -DDEMO_MODE

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nprobe ${PREFIX}/sbin

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
