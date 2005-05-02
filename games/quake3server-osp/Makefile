# $NetBSD: Makefile,v 1.2 2005/05/02 23:02:06 reed Exp $

DISTNAME=	osp-Quake3-1.03a_full
PKGNAME=	quake3server-osp-1.03a
CATEGORIES=	games net
MASTER_SITES=	http://files.l33tgames.com/files/q3/mods/osp/ \
		http://www.flatlands.ch/filebase/mods/left/
EXTRACT_SUFX=	.zip

MAINTAINER=	david@silicium.ath.cx
COMMENT=	Quake III Arena Mod: OSP Tourney DM/CA/CTF for Linux

.include "../../games/quake3server/Makefile.common"

DEPENDS+=	quake3server>=1.32:../../games/quake3server
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/osp
Q3MODDIR=	${Q3ROOTDIR}/osp

do-install:
	${INSTALL_DATA_DIR} ${Q3MODDIR}
	cd ${WRKSRC} && ${PAX} -rw . ${Q3MODDIR}

.include "../../mk/bsd.pkg.mk"
