# $NetBSD: Makefile,v 1.9 2015/03/06 19:54:09 tnn Exp $

DISTNAME=	excessive_q3_server_003
PKGNAME=	quake3server-excessive-003
PKGREVISION=	1
CATEGORIES=	games net
MASTER_SITES=	http://distcache.FreeBSD.org/ports-distfiles/
EXTRACT_SUFX=	.zip

MAINTAINER=	david@silicium.ath.cx
COMMENT=	Quake III Arena Mod: Excessive for Linux

WRKSRC=		${WRKDIR}

.include "../../games/quake3server/Makefile.common"

DEPENDS+=	quake3server>=1.32:../../games/quake3server
USE_TOOLS+=	pax

NO_BUILD=	yes
Q3MODDIR=	${Q3ROOTDIR}/excessive

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${Q3MODDIR}
	cd ${WRKSRC}/excessive && pax -rwppm . ${DESTDIR}${Q3MODDIR}

.include "../../mk/bsd.pkg.mk"
