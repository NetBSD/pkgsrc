# $NetBSD: Makefile,v 1.6 2005/12/05 20:51:01 rillig Exp $

DISTNAME=	scsiinfo-4.7
CATEGORIES=	sysutils
MASTER_SITES=	http://www.cs.toronto.edu/pub/jdd/scsiinfo/
EXTRACT_SUFX=	.shar

MAINTAINER=	grant@NetBSD.org
HOMEPAGE=	${MASTER_SITES}
COMMENT=	Displays information about SCSI devices attached to a system

WRKSRC=		${WRKDIR}

ONLY_FOR_PLATFORM=	SunOS-*-*

INSTALLATION_DIRS=	man/man1 sbin

do-extract:
	cd ${WRKSRC} && \
		${SH} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} >/dev/null

pre-build:
	cd ${WRKSRC} && ./mkadapters esp isp fas glm ptisp pln > adapters

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/scsiinfo ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/scsiinfo.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
