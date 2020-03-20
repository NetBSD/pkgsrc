# $NetBSD: Makefile,v 1.5 2020/03/20 11:58:22 nia Exp $

DISTNAME=	mrsync.20090219
PKGNAME=	${DISTNAME:S/./-/}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mrsync/}
EXTRACT_SUFX=	.zip

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://mrsync.sourceforge.net/
COMMENT=	Multicast data replication and synchronisation tool
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	bin

pre-configure:
	cd ${WRKSRC} && cp Makefile.linux Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/multicaster ${DESTDIR}${PREFIX}/bin/multicaster
	${INSTALL_PROGRAM} ${WRKSRC}/multicatcher ${DESTDIR}${PREFIX}/bin/multicatcher
	${INSTALL_PROGRAM} ${WRKSRC}/rtt ${DESTDIR}${PREFIX}/bin/rtt
	${INSTALL_PROGRAM} ${WRKSRC}/rttcatcher ${DESTDIR}${PREFIX}/bin/rttcatcher
	${INSTALL_PROGRAM} ${WRKSRC}/trFilelist ${DESTDIR}${PREFIX}/bin/trFilelist

.include "../../mk/bsd.pkg.mk"
