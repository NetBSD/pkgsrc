# $NetBSD: Makefile,v 1.3 2005/05/02 23:02:06 reed Exp $

DISTNAME=	excessive_q3_server_003
PKGNAME=	quake3server-excessive-003
CATEGORIES=	games net
MASTER_SITES=	ftp://ftp.fr.FreeBSD.org/pub/FreeBSD/distfiles/

MAINTAINER=	david@silicium.ath.cx
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
