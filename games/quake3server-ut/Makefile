# $NetBSD: Makefile,v 1.4 2005/05/02 23:02:06 reed Exp $

DISTNAME=	urbanterror3
PKGNAME=	quake3server-ut-3.0
CATEGORIES=	games net
DISTFILES=	urbanterror3.zip

MASTER_SITES=	http://64.159.80.11/ \
		ftp://mirror.candidhosting.com/pub/ut/ \
		http://box3.fsk405.org/q3ut3/ \
		http://fsk405.org/q3ut3/ \
		ftp://www.playdedicated.com/pub/sid/quake3/ \
		ftp://ftp.edome.net/online/clientit/ \
		http://atrivo.wofut.com/~zac/

MAINTAINER=	david@silicium.ath.cx
COMMENT=	Quake III Arena Mod: Urban Terror 3 for Linux

.include "../../games/quake3server/Makefile.common"

DEPENDS+=	quake3server>=1.32:../../games/quake3server
ONLY_FOR_PLATFORM=	NetBSD-*-i386
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/q3ut3
Q3MODDIR=	${Q3ROOTDIR}/ut
DOCDIR=		${PREFIX}/share/doc/lokigames/quake3server/ut
MESSAGE_SUBST+=	Q3MODDIR=${Q3MODDIR}

do-install:
	${INSTALL_DATA_DIR} ${Q3MODDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}

	${INSTALL_DATA} ${WRKSRC}/zq3ut3.pk3 ${Q3MODDIR}

	for docfile in readme.txt overview.txt radio\ commands.txt; do \
		${INSTALL_DATA} "${WRKSRC}/$${docfile}" ${DOCDIR}; \
	done

.include "../../mk/bsd.pkg.mk"
