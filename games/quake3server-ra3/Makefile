# $NetBSD: Makefile,v 1.8 2012/10/06 11:54:52 asau Exp $

DISTNAME=	ra3-1.65
PKGNAME=	quake3server-ra3-1.65
PKGREVISION=	1
CATEGORIES=	games net
MASTER_SITES?=	http://gamefiles.blueyonder.co.uk/blueyondergames/quake3arena/modifications/rocketarena/patches/linux/ \
		http://mir2.ovh.net/ftp.planetquake3.net/modifications/rocketarena3/
DISTFILES=	ra3165cl.zip \
		ra3165sv.zip

MAINTAINER=	david@silicium.ath.cx
COMMENT=	Quake III Arena Mod: Rocket Arena 3 for Linux

.include "../../games/quake3server/Makefile.common"

DEPENDS+=	quake3server>=1.32:../../games/quake3server
ONLY_FOR_PLATFORM=	NetBSD-*-i386
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/arena
Q3MODDIR=	${Q3ROOTDIR}/arena
DOCDIR=		${PREFIX}/share/doc/lokigames/quake3server/arena

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR]${Q3MODDIR}
	${INSTALL_DATA_DIR} ${DESTDIR]${DOCDIR}
.for datafile in *.pk3 qagame* *.cfg
	${INSTALL_DATA} ${WRKSRC}/${datafile} ${DESTDIR]${Q3MODDIR}
.endfor

.for docfile in readme.txt readsrv.txt
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${DESTDIR]${DOCDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
