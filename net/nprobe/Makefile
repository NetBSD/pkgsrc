# $NetBSD: Makefile,v 1.7 2003/05/02 11:56:10 wiz Exp $

DISTNAME=	nProbe-source-1.3.1
PKGREVISION=	1
PKGNAME=	nprobe-1.3.1
WRKSRC=		${WRKDIR}/nProbe
CATEGORIES=	net
MASTER_SITES=	http://luca.ntop.org/nprobeDownload/
EXTRACT_SUFX=	.tgz

MAINTAINER=	cjs@netbsd.org
HOMEPAGE=	http://www.ntop.org/nProbe.html
COMMENT=	Monitor a network interface and generate NetFlow data

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_GMAKE=	YES
ALL_TARGET=	nprobe

INTERACTIVE_STAGE=	fetch

# Uncomment this to make a demo version of nprobe.
#CFLAGS+=	-DMAX_DEMO_FLOWS=1000 -DDEMO_MODE

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nprobe ${PREFIX}/sbin

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
