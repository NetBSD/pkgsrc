# $NetBSD: Makefile,v 1.1.1.1 2000/02/02 06:50:34 itojun Exp $
# Based on FreeBSD ports/games/quakeserver
# FreeBSD: ports/games/quakeserver/Makefile,v 1.20 1999/08/31 06:44:23 mharo Exp
#

DISTNAME=	quake106
PKGNAME=	quakedata-1.0
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.cdrom.com/pub/quake/planetquake/threewave/unix/ \
		ftp://ftp.idsoftware.com/idstuff/quake/
EXTRACT_SUFX=	.zip

MAINTAINER=	itojun@kame.net
HOMEPAGE=	http://www.idsoftware.com/

BUILD_DEPENDS=	unzip:../../archivers/unzip \
		lha:../../archivers/lha

NO_WRKSUBDIR=	YES
NO_BUILD=	YES
NO_CDROM=	"This software is shareware"
LICENSE+=	shareware

do-extract:
		${RM} -rf ${WRKDIR}
		${MKDIR} ${WRKDIR}
		unzip -q -o ${DISTDIR}/quake106.zip -d ${WRKDIR} resource.*
		${CAT} ${WRKDIR}/resource.dat ${WRKDIR}/resource.1 > ${WRKDIR}/resource.exe
		cd ${WRKDIR}; lha xfq resource.exe id1/pak0.pak

do-install:
		${MKDIR} ${PREFIX}/share/quake/id1
		${INSTALL_DATA} ${WRKSRC}/id1/pak0.pak ${PREFIX}/share/quake/id1

.include "../../mk/bsd.pkg.mk"
