# $NetBSD: Makefile,v 1.1 2002/08/05 08:26:07 cjs Exp $

DISTNAME=	nProbe-source-1.3a
PKGNAME=	nprobe-1.3a
CATEGORIES=	net
MASTER_SITES=	http://luca.ntop.org/nprobeDownload/
# This program is not available anywhere else but the ntop site.
MASTER_SITE_BACKUP=
EXTRACT_SUFX=	.tgz

MAINTAINER=	cjs@netbsd.org
HOMEPAGE=	http://www.ntop.org/nProbe.html
COMMENT=	Monitor a network interface and generate NetFlow data

WRKSRC=		${WRKDIR}/nProbe
GNU_CONFIGURE=	YES
USE_GMAKE=	YES
ALL_TARGET=	nprobe

# Uncomment this to make a demo version of nprobe.
#CFLAGS+=	-DMAX_DEMO_FLOWS=1000 -DDEMO_MODE

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nprobe ${PREFIX}/sbin

.include "../../mk/pthread.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
