# $NetBSD: Makefile,v 1.7 2008/05/26 02:13:23 joerg Exp $

ftp://ftp.freenet.de/pub/4players/teamspeak.org/developer/server/202319/ts2_server_rc2_202319.tar.bz2

PKGNAME=		teamspeak-server-2.0.23.19
DISTNAME=		ts2_server_rc2_202319
CATEGORIES=		net audio
MASTER_SITES=		ftp://ftp.freenet.de/pub/4players/teamspeak.org/developer/server/202319/
EXTRACT_SUFX=		.tar.bz2
# EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=		abs@NetBSD.org
HOMEPAGE=		http://www.goteamspeak.com/
COMMENT=		Teamspeak group VoIP server

RESTRICTED=             Redistribution to third parties is expressly prohibited
NO_SRC_ON_CDROM=        ${RESTRICTED}
NO_BIN_ON_FTP=          ${RESTRICTED}
NO_BIN_ON_CDROM=        ${RESTRICTED}
LICENSE=		teamspeak-license-200700213

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	base

RCD_SCRIPTS=		teamspeak

PLIST_SRC=		${WRKDIR}/PLIST

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

PKG_GROUPS_VARS+=	TSGROUP
PKG_USERS_VARS+=	TSUSER
BUILD_DEFS+=		TSHOME

PKG_GROUPS=		${TSGROUP}
PKG_USERS=		${TSUSER}:${TSGROUP}
PKG_GECOS.${TSUSER}=	Teamspeak server user
PKG_HOME.${TSUSER}=	${TSHOME}
PKG_SHELL.${TSUSER}=	${SH}

FILES_SUBST+=   	TSUSER=${TSUSER}

INSTALLATION_DIRS=	${LIB_DIR} share/examples/rc.d ${SHARE_DIR}/httpdocs \
			${SHARE_DIR}/tcpquerydocs ${SHARE_DIR}/mysql_sql \
			${SHARE_DIR}/sqlite_sql ${DOC_DIR}/Manual

USE_TOOLS+=	pax

do-build:
	${MV} ${WRKSRC}/Manual/_TeamSpeak\ RC2\ Server\ manual-1.png \
	      ${WRKSRC}/Manual/_TeamSpeak_RC2_Server_manual-1.png

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/server_linux ${LIB_DIR}/teamspeak-server
	${INSTALL_LIB} ${WRKSRC}/*.so* ${LIB_DIR}
	${INSTALL_SCRIPT} -m 644 ${FILESDIR}/teamspeak.sh ${PREFIX}/share/examples/rc.d/teamspeak
	for d in httpdocs tcpquerydocs mysql_sql sqlite_sql ; do \
	cd ${WRKSRC}/$$d && pax -rw . ${SHARE_DIR}/$$d;\
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${SHARE_DIR}/$$d;\
	${FIND} ${SHARE_DIR}/$$d -type f -print | ${XARGS} ${CHMOD} ${SHAREMODE};\
	done
	${INSTALL_DATA} -m 644 ${WRKSRC}/Manual/* ${DOC_DIR}/Manual
	${INSTALL_DATA} -m 644 ${WRKSRC}/manual.html ${DOC_DIR}
	${INSTALL_DATA} -m 644 ${WRKSRC}/README ${DOC_DIR}
	${INSTALL_DATA} -m 644 ${WRKSRC}/INSTALL ${DOC_DIR}
	${INSTALL_DATA} -m 644 ${WRKSRC}/INSTALL.mysql ${DOC_DIR}
	${CAT} ${PKGDIR}/PLIST > ${PLIST_SRC}
	(cd ${PREFIX}; ${FIND} lib/teamspeak-server share/doc/teamspeak-server share/teamspeak-server -type f -print ) >> ${PLIST_SRC}
	(cd ${PREFIX}; ${FIND} lib/teamspeak-server share/doc/teamspeak-server share/teamspeak-server -type d -print ) | ${SED} 's/^/@dirrm /' | ${SORT} -r >> ${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
