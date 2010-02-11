# $NetBSD: Makefile,v 1.19 2010/02/11 22:19:44 joerg Exp $

DISTNAME=	nProbe-source-1.3.1
PKGREVISION=	4
PKGNAME=	nprobe-1.3.1
CATEGORIES=	net
MASTER_SITES=	http://luca.ntop.org/nprobeDownload/
EXTRACT_SUFX=	.tgz

MAINTAINER=	cjs@NetBSD.org
HOMEPAGE=	http://www.ntop.org/nProbe.html
COMMENT=	Monitor a network interface and generate NetFlow data

PKG_DESTDIR_SUPPORT=	user-destdir

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
