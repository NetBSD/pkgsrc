# $NetBSD: Makefile,v 1.9 2010/01/27 20:00:36 joerg Exp $

DISTNAME=	scsiinfo-4.7
CATEGORIES=	sysutils
MASTER_SITES=	http://www.cs.toronto.edu/pub/jdd/scsiinfo/
EXTRACT_SUFX=	.shar

MAINTAINER=	grant@NetBSD.org
HOMEPAGE=	${MASTER_SITES}
COMMENT=	Displays information about SCSI devices attached to a system

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}

ONLY_FOR_PLATFORM=	SunOS-*-*

INSTALLATION_DIRS=	${PKGMANDIR}/man1 sbin

do-extract:
	cd ${WRKSRC} && \
		${SH} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} >/dev/null

pre-build:
	cd ${WRKSRC} && ./mkadapters esp isp fas glm ptisp pln > adapters

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/scsiinfo ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/scsiinfo.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
