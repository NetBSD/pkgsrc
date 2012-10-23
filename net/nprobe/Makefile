# $NetBSD: Makefile,v 1.21 2012/10/23 17:18:42 asau Exp $

DISTNAME=	nProbe-source-1.3.1
PKGREVISION=	4
PKGNAME=	nprobe-1.3.1
CATEGORIES=	net
MASTER_SITES=	http://luca.ntop.org/nprobeDownload/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ntop.org/nProbe.html
COMMENT=	Monitor a network interface and generate NetFlow data

WRKSRC=		${WRKDIR}/nProbe
GNU_CONFIGURE=	YES
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake
BUILD_TARGET=	nprobe

INSTALLATION_DIRS=	sbin

# Uncomment this to make a demo version of nprobe.
#CFLAGS+=	-DMAX_DEMO_FLOWS=1000 -DDEMO_MODE

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nprobe ${DESTDIR}${PREFIX}/sbin

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
