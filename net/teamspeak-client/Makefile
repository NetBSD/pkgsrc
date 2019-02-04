# $NetBSD: Makefile,v 1.13 2019/02/04 09:34:49 wiz Exp $

PKGNAME=		teamspeak-client-2.0.32.60
DISTNAME=		ts2_client_rc2_2032
CATEGORIES=		net audio
MASTER_SITES=		#
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		abs@NetBSD.org
HOMEPAGE=		http://www.goteamspeak.com/
COMMENT=		Teamspeak group VoIP client
LICENSE=		teamspeak-license-200700213

RESTRICTED=		Redistribution to third parties is expressly prohibited
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	base jpeg x11

PLIST_SRC=		${WRKDIR}/PLIST

WRKSRC=		${WRKDIR}/${DISTNAME}/setup.data/image
LIB_DIR=	${PREFIX}/lib/teamspeak-client
DOC_DIR=	${PREFIX}/share/doc/teamspeak-client

do-build:
	${SED} "s|%installdir%|${LIB_DIR}|" ${WRKSRC}/TeamSpeak \
						> ${WRKDIR}/TeamSpeak

INSTALLATION_DIRS=	bin ${LIB_DIR}/sounds ${DOC_DIR}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/TeamSpeak ${DESTDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/TeamSpeak.bin ${DESTDIR}${LIB_DIR}
	${INSTALL_DATA} ${WRKSRC}/icon.xpm ${DESTDIR}${LIB_DIR}
	${INSTALL_DATA} ${WRKSRC}/sounds/* ${DESTDIR}${LIB_DIR}/sounds
	${INSTALL_LIB} ${WRKSRC}/*.so* ${DESTDIR}${LIB_DIR}
	${INSTALL_DATA} -m 644 ${WRKSRC}/Readme.txt ${DESTDIR}${DOC_DIR}
	${INSTALL_DATA} -m 644 ${WRKSRC}/clicense.txt ${DESTDIR}${DOC_DIR}
	${INSTALL_DATA} -m 644 ${WRKSRC}/manual/* ${DESTDIR}${DOC_DIR}
	${CAT} ${PKGDIR}/PLIST > ${PLIST_SRC}
	(cd ${DESTDIR}${PREFIX}; ${FIND} lib/teamspeak-client share/doc/teamspeak-client -type f -print ) >> ${PLIST_SRC}


.include "../../mk/bsd.pkg.mk"
