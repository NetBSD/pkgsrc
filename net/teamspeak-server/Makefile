# $NetBSD: Makefile,v 1.2 2007/05/01 11:34:05 abs Exp $

PKGNAME=		teamspeak-server-2.0.23.15
DISTNAME=		ts2_server_rc2_20201
CATEGORIES=		net audio
MASTER_SITES=		ftp://ftp.freenet.de/pub/4players/teamspeak.org/releases/
SITES.server_linux=	ftp://ftp.freenet.de/pub/4players/teamspeak.org/developer/server/202315/
EXTRACT_SUFX=		.tar.bz2
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} server_linux
DIST_SUBDIR=		teamspeak
EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=		abs@NetBSD.org
HOMEPAGE=		http://www.goteamspeak.com/
COMMENT=		Teamspeak group VoIP server

.include "../../emulators/suse_linux/Makefile.application"

.if !defined(USE_NATIVE_LINUX)
DEPENDS+=	suse_base-[0-9]*:../../emulators/${SUSE_DIR_PREFIX}_base
.endif

ONLY_FOR_PLATFORM=	*-*-i386

RCD_SCRIPTS=		teamspeak
NO_CONFIGURE=		yes
USE_LANGUAGES=

PLIST_SRC=		${WRKDIR}/PLIST

RESTRICTED=             Redistribution to third parties is expressly prohibited
NO_SRC_ON_CDROM=        ${RESTRICTED}
NO_BIN_ON_FTP=          ${RESTRICTED}
NO_BIN_ON_CDROM=        ${RESTRICTED}
LICENSE=		teamspeak-license-200700213

WRKSRC=		${WRKDIR}/tss2_rc2
EGDIR=		${PREFIX}/share/examples
LIB_DIR=	${PREFIX}/lib/teamspeak-server
DOC_DIR=	${PREFIX}/share/doc/teamspeak-server
SHARE_DIR=	${PREFIX}/share/teamspeak-server
HOMEBASE?=	${VARBASE}

# TSUSER	username of the teamspeak server user
# TSGROUP	group of the teamspeak server user
# TSHOME	home directory for the teamspeak server data
#
TSUSER?=		teamspeak
TSGROUP?=		teamspeak
TSHOME?=		${HOMEBASE}/${TSUSER}

BUILD_DEFS+=		TSUSER TSGROUP TSHOME

PKG_GROUPS=		${TSGROUP}
PKG_USERS=		${TSUSER}:${TSGROUP}
PKG_GECOS.${TSUSER}=	Teamspeak server user
PKG_HOME.${TSUSER}=	${TSHOME}
PKG_SHELL.${TSUSER}=	${SH}

FILES_SUBST+=   	TSUSER=${TSUSER}

do-build:
	${MV} ${WRKSRC}/Manual/_TeamSpeak\ RC2\ Server\ manual-1.png \
	      ${WRKSRC}/Manual/_TeamSpeak_RC2_Server_manual-1.png

do-install:
	${INSTALL_DATA_DIR} ${LIB_DIR}
	${INSTALL_PROGRAM} ${DISTDIR}/${DIST_SUBDIR}/server_linux ${LIB_DIR}/teamspeak-server
	${INSTALL_LIB} ${WRKSRC}/*.so* ${LIB_DIR}
	${INSTALL_SCRIPT} -m 644 ${FILESDIR}/teamspeak.sh ${PREFIX}/share/examples/rc.d/teamspeak
	for d in httpdocs tcpquerydocs mysql_sql sqlite_sql ; do \
	${INSTALL_DATA_DIR} ${SHARE_DIR}/$$d;\
	cd ${WRKSRC}/$$d && ${PAX} -rw . ${SHARE_DIR}/$$d;\
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${SHARE_DIR}/$$d;\
	${FIND} ${SHARE_DIR}/$$d -type f -print | ${XARGS} ${CHMOD} ${SHAREMODE};\
	done
	${INSTALL_DATA_DIR} ${DOC_DIR}/Manual
	${INSTALL_DATA} -m 644 ${WRKSRC}/Manual/* ${DOC_DIR}/Manual
	${INSTALL_DATA} -m 644 ${WRKSRC}/changelog.txt ${DOC_DIR}
	${INSTALL_DATA} -m 644 ${WRKSRC}/manual.html ${DOC_DIR}
	${INSTALL_DATA} -m 644 ${WRKSRC}/README ${DOC_DIR}
	${INSTALL_DATA} -m 644 ${WRKSRC}/INSTALL ${DOC_DIR}
	${INSTALL_DATA} -m 644 ${WRKSRC}/INSTALL.mysql ${DOC_DIR}
	${CAT} ${PKGDIR}/PLIST > ${PLIST_SRC}
	(cd ${PREFIX}; ${FIND} lib/teamspeak-server share/doc/teamspeak-server share/teamspeak-server -type f -print ) >> ${PLIST_SRC}
	(cd ${PREFIX}; ${FIND} lib/teamspeak-server share/doc/teamspeak-server share/teamspeak-server -type d -print ) | ${SED} 's/^/@dirrm /' | ${SORT} -r >> ${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
