# $NetBSD: Makefile,v 1.2 2004/05/07 15:25:13 cjep Exp $

DISTNAME=	excessive_q3_server_003
PKGNAME=	quake3server-excessive-003
CATEGORIES=	games net
MASTER_SITES=	ftp://ftp.fr.FreeBSD.org/pub/FreeBSD/distfiles/

MAINTAINER=	david@netbsd-fr.org
COMMENT=	Quake III Arena Mod: Excessive for Linux

EXTRACT_SUFX=	.zip
WRKSRC=		${WRKDIR}

.include "../../games/quake3server/Makefile.common"

DEPENDS+=	quake3server>=1.32:../../games/quake3server
ONLY_FOR_PLATFORM=	NetBSD-*-i386
NO_BUILD=	yes
Q3MODDIR=	${Q3ROOTDIR}/excessive

do-install:
	${INSTALL_DATA_DIR} ${Q3MODDIR}
	cd ${WRKSRC}/excessive && ${PAX} -rwppm . ${Q3MODDIR}

.include "../../mk/bsd.pkg.mk"
