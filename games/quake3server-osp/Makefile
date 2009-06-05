# $NetBSD: Makefile,v 1.6 2009/06/05 22:33:53 zafer Exp $

DISTNAME=	osp-Quake3-1.03a_full
PKGNAME=	quake3server-osp-1.03a
PKGREVISION=	1
CATEGORIES=	games net
MASTER_SITES=	${MASTER_SITE_GENTOO:=distfiles/}
EXTRACT_SUFX=	.zip

MAINTAINER=	david@silicium.ath.cx
COMMENT=	Quake III Arena Mod: OSP Tourney DM/CA/CTF for Linux

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../games/quake3server/Makefile.common"

DEPENDS+=	quake3server>=1.32:../../games/quake3server
USE_TOOLS+=	pax

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/osp
Q3MODDIR=	${Q3ROOTDIR}/osp

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${Q3MODDIR}
	cd ${WRKSRC} && pax -rw . ${DESTDIR}${Q3MODDIR}

.include "../../mk/bsd.pkg.mk"
