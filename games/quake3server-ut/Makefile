# $NetBSD: Makefile,v 1.9 2013/04/08 11:17:14 rodent Exp $

DISTNAME=	urbanterror3
PKGNAME=	quake3server-ut-3.0
PKGREVISION=	1
CATEGORIES=	games net
DISTFILES=	urbanterror3.zip

MASTER_SITES=	http://distfiles.aydogan.net/games/

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
	${INSTALL_DATA_DIR} ${DESTDIR}${Q3MODDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}

	${INSTALL_DATA} ${WRKSRC}/zq3ut3.pk3 ${DESTDIR}${Q3MODDIR}

	for docfile in readme.txt overview.txt radio\ commands.txt; do \
		${INSTALL_DATA} "${WRKSRC}/$${docfile}" ${DESTDIR}${DOCDIR}; \
	done

.include "../../mk/bsd.pkg.mk"
