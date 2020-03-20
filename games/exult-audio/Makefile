# $NetBSD: Makefile,v 1.4 2020/03/20 11:57:41 nia Exp $

DISTNAME=	exult_audio
PKGNAME=	exultaudio-1.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=exult/exult-data/}
EXTRACT_SUFX=	.zip

MAINTAINER=	nikkohigashi@gmail.com
HOMEPAGE=	http://exult.sourceforge.net/
COMMENT=	Digital music and digital wave sound effects data for Exult
LICENSE=	gnu-gpl-v2

DEPENDS+=	exult>=1.4.9rc1:../../games/exult

DIST_SUBDIR=	${PKGNAME_NOREV}

NO_CONFIGURE=	yes
NO_BUILD=	yes

EXTRACT_DIR=		${WRKDIR}/exult-data
EXULTDIR=		${DESTDIR}/${PREFIX}/share/exult
INSTALLATION_DIRS+=	share/exult/music

do-install:
	${INSTALL_DATA} ${EXTRACT_DIR}/*.flx ${EXULTDIR}/
	${INSTALL_DATA} ${EXTRACT_DIR}/*.txt ${EXULTDIR}/
	${INSTALL_DATA} ${EXTRACT_DIR}/music/*.ogg ${EXULTDIR}/music/
	${INSTALL_DATA} ${EXTRACT_DIR}/music/*.txt ${EXULTDIR}/music/

.include "../../mk/bsd.pkg.mk"
