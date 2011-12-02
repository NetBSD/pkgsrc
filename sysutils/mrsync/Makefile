# $NetBSD: Makefile,v 1.1.1.1 2011/12/02 05:40:00 agc Exp $

DISTNAME=	mrsync.20090219
PKGNAME=	${DISTNAME:S/./-/}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mrsync/}
EXTRACT_SUFX=	.zip

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://mrsync.sourceforge.net/
COMMENT=	Multicast data replication and synchronisation tool
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

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
