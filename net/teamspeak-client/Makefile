# $NetBSD: Makefile,v 1.6 2007/07/29 05:19:47 jlam Exp $

PKGNAME=		teamspeak-client-2.0.32.60
DISTNAME=		ts2_client_rc2_2032
CATEGORIES=		net audio
MASTER_SITES=		ftp://ftp.freenet.de/pub/4players/teamspeak.org/releases/ \
			ftp://213.202.254.114/teamspeak/releases/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		abs@NetBSD.org
HOMEPAGE=		http://www.goteamspeak.com/
COMMENT=		Teamspeak group VoIP client

RESTRICTED=		Redistribution to third parties is expressly prohibited
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
LICENSE=		teamspeak-license-200700213

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	base jpeg x11

PLIST_SRC=		${WRKDIR}/PLIST

WRKSRC=		${WRKDIR}/${DISTNAME}/setup.data/image
LIB_DIR=	${PREFIX}/lib/teamspeak-client
DOC_DIR=	${PREFIX}/share/doc/teamspeak-client

do-build:
	${SED} "s|%installdir%|${LIB_DIR}|" ${WRKSRC}/TeamSpeak \
						> ${WRKDIR}/TeamSpeak

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/TeamSpeak ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${LIB_DIR}
	${INSTALL_DATA_DIR} ${LIB_DIR}/sounds
	${INSTALL_LIB} ${WRKSRC}/TeamSpeak.bin ${LIB_DIR}
	${INSTALL_LIB} ${WRKSRC}/icon.xpm ${LIB_DIR}
	${INSTALL_LIB} ${WRKSRC}/sounds/* ${LIB_DIR}/sounds
	${INSTALL_LIB} ${WRKSRC}/*.so* ${LIB_DIR}
	${INSTALL_DATA_DIR} ${DOC_DIR}
	${INSTALL_DATA} -m 644 ${WRKSRC}/Readme.txt ${DOC_DIR}
	${INSTALL_DATA} -m 644 ${WRKSRC}/clicense.txt ${DOC_DIR}
	${INSTALL_DATA} -m 644 ${WRKSRC}/manual/* ${DOC_DIR}
	${CAT} ${PKGDIR}/PLIST > ${PLIST_SRC}
	(cd ${PREFIX}; ${FIND} lib/teamspeak-client share/doc/teamspeak-client -type f -print ) >> ${PLIST_SRC}
	(cd ${PREFIX}; ${FIND} lib/teamspeak-client share/doc/teamspeak-client -type d -print ) | ${SED} 's/^/@dirrm /' | ${SORT} -r >> ${PLIST_SRC}


.include "../../mk/bsd.pkg.mk"
