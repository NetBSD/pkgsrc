# $NetBSD: Makefile,v 1.3 2003/07/21 17:24:34 martti Exp $

DISTNAME=	scsiinfo-4.7
PKGNAME=	${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	http://www.cs.toronto.edu/pub/jdd/scsiinfo/
EXTRACT_SUFX=	.shar

MAINTAINER=	grant@NetBSD.org
HOMEPAGE=	${MASTER_SITES}
COMMENT=	Displays information about SCSI devices attached to a system

ONLY_FOR_PLATFORM=	SunOS-*-*

do-extract:
	${MKDIR} ${WRKSRC}; cd ${WRKSRC}; \
	${SH} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} >/dev/null

pre-build:
	cd ${WRKSRC}; ./mkadapters esp isp fas glm ptisp pln > adapters

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/scsiinfo ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/scsiinfo.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"

