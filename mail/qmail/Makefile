# $NetBSD: Makefile,v 1.118 2020/03/18 17:56:09 joerg Exp $
#

DISTNAME=		notqmail-1.07
PKGNAME=		qmail-1.03
PKGREVISION=		48
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_GITHUB:=notqmail/}
GITHUB_PROJECT=		notqmail
GITHUB_RELEASE=		${DISTNAME}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://notqmail.org/
COMMENT=		Secure, reliable, efficient, simple, and fast MTA
LICENSE=		public-domain

DEPENDS+=		daemontools-[0-9]*:../../sysutils/daemontools

CONFLICTS+=		courier-maildirmake-[0-9]*
CONFLICTS+=		courier-mta-[0-9]*
CONFLICTS+=		mirrordir-[0-9]*
CONFLICTS+=		mutt<=1.4.2.1nb1
CONFLICTS+=		netqmail-[0-9]*
CONFLICTS+=		pulsar<=0.1.1
CONFLICTS+=		qmail-run<=20170706

DJB_CONFIG_CMDS+=	${ECHO} ${QMAIL_ALIAS_USER:Q}     > conf-users;
DJB_CONFIG_CMDS+=	${ECHO} ${QMAIL_DAEMON_USER:Q}   >> conf-users;
DJB_CONFIG_CMDS+=	${ECHO} ${QMAIL_LOG_USER:Q}      >> conf-users;
DJB_CONFIG_CMDS+=	${ECHO} ${QMAIL_ROOT_USER:Q}     >> conf-users;
DJB_CONFIG_CMDS+=	${ECHO} ${QMAIL_PASSWD_USER:Q}   >> conf-users;
DJB_CONFIG_CMDS+=	${ECHO} ${QMAIL_QUEUE_USER:Q}    >> conf-users;
DJB_CONFIG_CMDS+=	${ECHO} ${QMAIL_REMOTE_USER:Q}   >> conf-users;
DJB_CONFIG_CMDS+=	${ECHO} ${QMAIL_SEND_USER:Q}     >> conf-users;
DJB_CONFIG_CMDS+=	${ECHO} ${QMAIL_QMAIL_GROUP:Q}    > conf-groups;
DJB_CONFIG_CMDS+=	${ECHO} ${QMAIL_NOFILES_GROUP:Q} >> conf-groups;
DJB_BUILD_TARGETS=	man
DJB_RESTRICTED=		no

PKG_SYSCONFSUBDIR=	qmail
OWN_DIRS+=		${PKG_SYSCONFDIR} ${PKG_SYSCONFDIR}/alias
OWN_DIRS+=		${PKG_SYSCONFDIR}/control ${PKG_SYSCONFDIR}/users
OWN_DIRS+=		${PKG_SYSCONFDIR}/.pkgsrc-defaults-do-not-edit
OWN_DIRS+=		${QMAILDIR} ${QMAIL_QUEUE_DIR}

DOCDIR=			${PREFIX}/share/doc/qmail
EGDIR=			${PREFIX}/share/examples/qmail
SHAREDIR=		${PREFIX}/share/qmail
FILES_SUBST+=		DOCDIR=${DOCDIR:Q} EGDIR=${EGDIR:Q}
FILES_SUBST+=		PKGMANDIR=${PKGMANDIR:Q} SHAREDIR=${SHAREDIR:Q}
FILES_SUBST+=		QMAILDIR=${QMAILDIR:Q}
FILES_SUBST+=		QMAIL_DAEMON_USER=${QMAIL_DAEMON_USER:Q}
FILES_SUBST+=		QMAIL_QMAIL_GROUP=${QMAIL_QMAIL_GROUP:Q}
FILES_SUBST+=		QMAIL_QUEUE_DIR=${QMAIL_QUEUE_DIR:Q}
FILES_SUBST+=		QMAIL_QUEUE_EXTRA=${QMAIL_QUEUE_EXTRA:Q}
FILES_SUBST+=		PKGNAME=${PKGNAME:Q}
FILES_SUBST+=		WC=${WC:Q}

SETUP_PROGRAMS=		dnsfq dnsip dnsptr hostname ipmeprint
SETUP_PROGRAMS+=	instpackage instchown instcheck
SETUP_SCRIPTS=		config config-fast config-fast-pkgsrc

MANDIRS=		man
.for j in 1 5 7 8
MANDIRS+=		man/man${j}
.endfor
INSTALLATION_DIRS=	bin ${MANDIRS} ${DOCDIR} ${SHAREDIR}
INSTALLATION_DIRS+=	${EGDIR}/alias ${EGDIR}/boot ${EGDIR}/control
INSTALLATION_DIRS+=	${EGDIR}/users

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		QMAILDIR QMAILPATCHES QMAIL_QUEUE_DIR QMAIL_QUEUE_EXTRA
BUILD_DEFS+=		QMAIL_ALIAS_USER QMAIL_DAEMON_USER QMAIL_LOG_USER
BUILD_DEFS+=		QMAIL_ROOT_USER QMAIL_PASSWD_USER QMAIL_QUEUE_USER
BUILD_DEFS+=		QMAIL_REMOTE_USER QMAIL_SEND_USER
BUILD_DEFS+=		QMAIL_QMAIL_GROUP QMAIL_NOFILES_GROUP

.if !empty(QMAIL_QUEUE_DIR:M${QMAILDIR}/*)
PKG_FAIL_REASON+=	"QMAIL_QUEUE_DIR must not be under ${QMAILDIR}"
.endif

USE_TOOLS+=		tar

.if !empty(QMAIL_QUEUE_EXTRA)
USE_TOOLS+=		expr
QUEUE_EXTRA=		"T${QMAIL_QUEUE_EXTRA}\\0"
QUEUE_EXTRALEN_cmd=	${EXPR} `${ECHO_N} ${QMAIL_QUEUE_EXTRA} | ${WC} -c` + 2
SUBST_CLASSES+=		logging
SUBST_STAGE.logging=	do-configure
SUBST_FILES.logging=	extra.h
SUBST_SED.logging=	-e 's|0|${QUEUE_EXTRALEN_cmd:sh}|g'
SUBST_SED.logging+=	-e 's|""|${QUEUE_EXTRA}|g'
SUBST_MESSAGE.logging=	Setting QUEUE_EXTRA.
.endif

SUBST_CLASSES+=		catpages
SUBST_STAGE.catpages=	do-configure
SUBST_FILES.catpages=	hier.c
SUBST_SED.catpages=	-e 's|.*"man/cat[0-9]".*||g'
SUBST_SED.catpages+=	-e 's|.*"tcp-environ\.5".*||g'	# also in ucspi-tcp

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	do-configure
SUBST_FILES.paths=	README.*
SUBST_VARS.paths=	PKGNAME PKG_INFO PREFIX GREP

SUBST_CLASSES+=		config
SUBST_STAGE.config=	do-configure
SUBST_FILES.config=	config-fast-pkgsrc-defaults.sh
SUBST_VARS.config=	SORT MV CP PKG_SYSCONFDIR QMAIL_QUEUE_EXTRA

SUBST_FILES.djbware+=	cdb_seek.c dns.c

PKG_USERS_VARS+=		QMAIL_ALIAS_USER QMAIL_DAEMON_USER QMAIL_LOG_USER
PKG_USERS_VARS+=		QMAIL_ROOT_USER QMAIL_PASSWD_USER QMAIL_QUEUE_USER
PKG_USERS_VARS+=		QMAIL_REMOTE_USER QMAIL_SEND_USER
PKG_GROUPS_VARS+=		QMAIL_QMAIL_GROUP QMAIL_NOFILES_GROUP
PKG_GROUPS=			${QMAIL_QMAIL_GROUP} ${QMAIL_NOFILES_GROUP}
PKG_USERS+=			${QMAIL_ALIAS_USER}:${QMAIL_NOFILES_GROUP}
PKG_USERS+=			${QMAIL_DAEMON_USER}:${QMAIL_NOFILES_GROUP}
PKG_USERS+=			${QMAIL_LOG_USER}:${QMAIL_NOFILES_GROUP}
PKG_USERS+=			${QMAIL_PASSWD_USER}:${QMAIL_NOFILES_GROUP}
PKG_USERS+=			${QMAIL_QUEUE_USER}:${QMAIL_QMAIL_GROUP}
PKG_USERS+=			${QMAIL_REMOTE_USER}:${QMAIL_QMAIL_GROUP}
PKG_USERS+=			${QMAIL_SEND_USER}:${QMAIL_QMAIL_GROUP}
.for user in ${PKG_USERS:C/\:.*//}
PKG_HOME.${user}=		${QMAILDIR}
.endfor
PKG_HOME.${QMAIL_ALIAS_USER}=	${QMAILDIR}/alias

READMES=		README.pkgsrc

# Record all patches applied, starting with the non-optional ones:
QMAILPATCHES=			notqmail:${DEFAULT_DISTFILES}

QMAILPATCHES+=			tls:${TLSREMOTE_PATCH}
TLSREMOTE_PATCH=		notqmail-1.07-tls-20200107-onlyremote-20200202.patch
PATCHFILES+=			${TLSREMOTE_PATCH}
SITES.${TLSREMOTE_PATCH}=	https://schmonz.com/qmail/tlsonlyremote/

QMAILPATCHES+=			bigdns:${BIGDNS_PATCH}
BIGDNS_PATCH=			qmail-103.patch
PATCHFILES+=			${BIGDNS_PATCH}
SITES.${BIGDNS_PATCH}=		https://www.ckdhr.com/ckd/
PATCH_DIST_STRIP.${BIGDNS_PATCH}= -p1

QMAILPATCHES+=				maildiruniq:${MAILDIRUNIQ_PATCH}
MAILDIRUNIQ_PATCH=			qmail-1.03-maildir-uniq.patch
PATCHFILES+=				${MAILDIRUNIQ_PATCH}
SITES.${MAILDIRUNIQ_PATCH}=		http://www.memoryhole.net/qmail/
PATCH_DIST_STRIP.${MAILDIRUNIQ_PATCH}=	-p1
PATCH_DIST_CAT.${MAILDIRUNIQ_PATCH}=	\
				${SED} -e 's|"057"|"\\\\057"|' \
				-e 's|"072"|"\\\\072"|' \
				< ${MAILDIRUNIQ_PATCH}

QMAILPATCHES+=			outgoingip:${OUTGOINGIP_PATCH}
OUTGOINGIP_PATCH=		outgoingip.patch
PATCHFILES+=			${OUTGOINGIP_PATCH}
SITES.${OUTGOINGIP_PATCH}=	http://qmailorg.schmonz.com/

QMAILPATCHES+=			remote:${REMOTE_PATCH}
REMOTE_PATCH=			notqmail-1.07-tls-20190517-qmailremote-20190819.patch
PATCHFILES+=			${REMOTE_PATCH}
SITES.${REMOTE_PATCH}=		https://schmonz.com/qmail/remote/

QMAILPATCHES+=			spp:${SPP_PATCH}:${SPP_PATCHFILE_cmd:sh}
SPP_PATCH=			qmail-spp-0.42.tar.gz
PATCHFILES+=			${SPP_PATCH}
SITES.${SPP_PATCH}=		${MASTER_SITE_SOURCEFORGE:=qmail-spp/}
SPP_PATCHFILE=			./qmail-spp-0.42/netqmail-spp.diff
SPP_PATCHFILE_cmd=		${BASENAME} ${SPP_PATCHFILE}
PATCH_DIST_CAT.${SPP_PATCH}=	${TAR} -C ${WRKDIR} -zxf ${SPP_PATCH} ${SPP_PATCHFILE} \
				&& ${CAT} ${WRKDIR}/${SPP_PATCHFILE} \
				| ${SED} -e 's|sppfok \!= 1|sppfok == -1|'
PATCH_DIST_STRIP.${SPP_PATCH}=	-p1
LICENSE+=			AND gnu-gpl-v2

post-extract:
	for i in ${READMES}; do						\
		${CP} ${FILESDIR}/$$i ${WRKSRC} || ${TRUE};		\
	done
	${CP} ${FILESDIR}/config-fast-pkgsrc-defaults.sh ${WRKSRC}
	for i in FILES; do						\
		${TOUCH} ${WRKSRC}/$$i;					\
	done

USE_TOOLS+=			sleep
post-build:
.if defined(MANZ)
	cd ${WRKSRC} && \
	${SLEEP} 2 && \
	${SED} -e 's|\(.*"man/man[0-9]",".*\.[0-9]\)|\1.gz|g' \
		< hier.c > hier.c.tmp && \
		${MV} hier.c.tmp hier.c && \
	${MAKE} instchown instcheck
.endif
	cd ${WRKSRC} && \
	${SED} -e 's|${QMAILDIR}/control/|${PKG_SYSCONFDIR}/.pkgsrc-defaults-do-not-edit/|' \
		< config-fast > config-fast-pkgsrc && \
	${CAT} ${WRKSRC}/config-fast-pkgsrc-defaults.sh \
		>> config-fast-pkgsrc

pre-install:
	${MKDIR} ${DESTDIR}${QMAILDIR}
	${MKDIR} ${DESTDIR}/tmp${QMAIL_QUEUE_DIR}
	# keep in sync with INSTALL:PRE-INSTALL
	${LN} -s ${DESTDIR}${EGDIR}/alias	${DESTDIR}${QMAILDIR}/alias
	${LN} -s ${DESTDIR}${PREFIX}/bin	${DESTDIR}${QMAILDIR}/bin
	${LN} -s ${DESTDIR}${EGDIR}/boot	${DESTDIR}${QMAILDIR}/boot
	${LN} -s ${DESTDIR}${EGDIR}/control	${DESTDIR}${QMAILDIR}/control
	${LN} -s ${DESTDIR}${DOCDIR}		${DESTDIR}${QMAILDIR}/doc
	${LN} -s ${DESTDIR}${PREFIX}/${PKGMANDIR} ${DESTDIR}${QMAILDIR}/man
	${LN} -s ${DESTDIR}/tmp${QMAIL_QUEUE_DIR} ${DESTDIR}${QMAILDIR}/queue
	${LN} -s ${DESTDIR}${EGDIR}/users	${DESTDIR}${QMAILDIR}/users

do-install:
	cd ${WRKSRC}; \
	DESTDIR=${DESTDIR:Q} ./instpackage

post-install:
	for i in ${READMES}; do						\
		${INSTALL_DATA} ${WRKSRC}/$$i ${DESTDIR}${DOCDIR};	\
	done

	${INSTALL_PROGRAM_DIR} ${DESTDIR}${SHAREDIR}/setup
	for i in ${SETUP_PROGRAMS}; do					\
		${INSTALL_PROGRAM} ${WRKSRC}/$$i			\
			${DESTDIR}${SHAREDIR}/setup;			\
	done
	for i in ${SETUP_SCRIPTS}; do					\
		${INSTALL_SCRIPT} ${WRKSRC}/$$i				\
			${DESTDIR}${SHAREDIR}/setup;			\
	done

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
