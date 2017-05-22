# $NetBSD: Makefile,v 1.86 2017/05/22 17:18:32 schmonz Exp $
#

DISTNAME=		${PKGNAME_NOREV}
PKGNAME=		qmail-1.03
PKGREVISION=		28
CATEGORIES=		mail
MASTER_SITES=		http://qmail.org/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://cr.yp.to/qmail.html
COMMENT=		Secure, reliable, efficient, simple, and fast MTA
LICENSE=		public-domain

DEPENDS+=		daemontools-[0-9]*:../../sysutils/daemontools
DEPENDS+=		queue-fix>=1.4nb1:../../mail/queue-fix
DEPENDS+=		ucspi-tcp-[0-9]*:../../net/ucspi-tcp

CONFLICTS+=		courier-maildirmake-[0-9]*
CONFLICTS+=		courier-mta-[0-9]*
CONFLICTS+=		mirrordir-[0-9]*
CONFLICTS+=		mutt<=1.4.2.1nb1
CONFLICTS+=		netqmail-[0-9]*
CONFLICTS+=		pulsar<=0.1.1

WRKSRC=			${WRKDIR}/${DISTNAME}

USE_TOOLS+=		nroff

DJB_CONFIG_CMDS=	${ECHO} ${DESTDIR:Q}${QMAILDIR:Q} > conf-destdir;
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
INSTALL_TARGET=		setup
DJB_RESTRICTED=		no

PKG_SYSCONFSUBDIR=	qmail
OWN_DIRS+=		${PKG_SYSCONFDIR} ${PKG_SYSCONFDIR}/alias
OWN_DIRS+=		${PKG_SYSCONFDIR}/control ${PKG_SYSCONFDIR}/users
OWN_DIRS+=		${QMAILDIR} ${QMAIL_QUEUE_DIR}

DOCDIR=			${PREFIX}/share/doc/qmail
EGDIR=			${PREFIX}/share/examples/qmail
SHAREDIR=		${PREFIX}/share/qmail
PLIST_SUBST+=		DARWINSUFX=${DARWINSUFX:Q}
MESSAGE_SRC+=		${PKGDIR}/MESSAGE
MESSAGE_SUBST+=		DOCDIR=${DOCDIR:Q} EGDIR=${EGDIR:Q}
FILES_SUBST+=		DOCDIR=${DOCDIR:Q} EGDIR=${EGDIR:Q}
FILES_SUBST+=		OPENSSL=${OPENSSL:Q}
FILES_SUBST+=		PKGMANDIR=${PKGMANDIR:Q} SHAREDIR=${SHAREDIR:Q}
FILES_SUBST+=		QMAILDIR=${QMAILDIR:Q}
FILES_SUBST+=		QMAIL_DAEMON_USER=${QMAIL_DAEMON_USER:Q}
FILES_SUBST+=		QMAIL_QMAIL_GROUP=${QMAIL_QMAIL_GROUP:Q}
FILES_SUBST+=		QMAIL_QUEUE_DIR=${QMAIL_QUEUE_DIR:Q}
FILES_SUBST+=		QMAIL_QUEUE_EXTRA=${QMAIL_QUEUE_EXTRA:Q}
FILES_SUBST+=		PKGNAME=${PKGNAME:Q}

SETUP_PROGRAMS=		dnsfq dnsip dnsptr hostname install ipmeprint
SETUP_SCRIPTS=		config config-fast

MANDIRS=		man
.for j in 1 5 7 8
MANDIRS+=		man/man${j}
.endfor
INSTALLATION_DIRS=	bin ${MANDIRS} ${DOCDIR} ${SHAREDIR}
INSTALLATION_DIRS+=	${EGDIR}/alias ${EGDIR}/boot ${EGDIR}/control
INSTALLATION_DIRS+=	${EGDIR}/users

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		QMAILDIR QMAIL_QUEUE_DIR QMAIL_QUEUE_EXTRA
BUILD_DEFS+=		QMAIL_ALIAS_USER QMAIL_DAEMON_USER QMAIL_LOG_USER
BUILD_DEFS+=		QMAIL_ROOT_USER QMAIL_PASSWD_USER QMAIL_QUEUE_USER
BUILD_DEFS+=		QMAIL_REMOTE_USER QMAIL_SEND_USER
BUILD_DEFS+=		QMAIL_QMAIL_GROUP QMAIL_NOFILES_GROUP

.if !empty(QMAIL_QUEUE_DIR:M${QMAILDIR}/*)
PKG_FAIL_REASON+=	"QMAIL_QUEUE_DIR must not be under ${QMAILDIR}"
.endif

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

SUBST_CLASSES+=		caseclash
SUBST_STAGE.caseclash=	do-configure
SUBST_FILES.caseclash=	hier.c
SUBST_SED.caseclash=	-e 's|"INSTALL"|"INSTALL${DARWINSUFX}"|g'
SUBST_SED.caseclash+=	-e 's|"SENDMAIL"|"SENDMAIL${DARWINSUFX}"|g'

SUBST_CLASSES+=		catpages
SUBST_STAGE.catpages=	do-configure
SUBST_FILES.catpages=	hier.c
SUBST_SED.catpages=	-e 's|.*"man/cat[0-9]".*||g'
SUBST_SED.catpages+=	-e 's|.*"tcp-environ\.5".*||g'	# also in ucspi-tcp

SUBST_CLASSES+=		destdir
SUBST_STAGE.destdir=	do-configure
SUBST_FILES.destdir=	Makefile
SUBST_SED.destdir=	-e 's|\(^load inst.*\.o\) auto_qmail\.o\(.*\)|\1 auto_destdir.o\2|g'
SUBST_SED.destdir+=	-e 's|\(^	\./load inst.*\) auto_qmail\.o\(.*\)|\1 auto_destdir.o\2|g'

SUBST_CLASSES+=		groups
SUBST_STAGE.groups=	do-configure
SUBST_FILES.groups=	auto_uids.c
SUBST_SED.groups=	-e 's,@QMAIL_QMAIL_GROUP@,${QMAIL_QMAIL_GROUP:Q},g'
SUBST_SED.groups+=	-e 's,@QMAIL_NOFILES_GROUP@,${QMAIL_NOFILES_GROUP:Q},g'

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	do-configure
SUBST_FILES.paths=	README.*
SUBST_SED.paths=	-e 's,@PKGNAME@,${PKGNAME:Q},g'
SUBST_SED.paths+=	-e 's,@PKG_INFO@,${PKG_INFO:Q},g'
SUBST_SED.paths+=	-e 's,@PREFIX@,${PREFIX:Q},g'
SUBST_SED.paths+=	-e 's,@GREP@,${GREP:Q},g'

SUBST_CLASSES+=		users
SUBST_STAGE.users=	do-configure
SUBST_FILES.users=	auto_uids.c
SUBST_SED.users=	-e 's,@QMAIL_ROOT_USER@,${QMAIL_ROOT_USER:Q},g'
SUBST_SED.users+=	-e 's,@QMAIL_ALIAS_USER@,${QMAIL_ALIAS_USER:Q},g'
SUBST_SED.users+=	-e 's,@QMAIL_DAEMON_USER@,${QMAIL_DAEMON_USER:Q},g'
SUBST_SED.users+=	-e 's,@QMAIL_LOG_USER@,${QMAIL_LOG_USER:Q},g'
SUBST_SED.users+=	-e 's,@QMAIL_PASSWD_USER@,${QMAIL_PASSWD_USER:Q},g'
SUBST_SED.users+=	-e 's,@QMAIL_QUEUE_USER@,${QMAIL_QUEUE_USER:Q},g'
SUBST_SED.users+=	-e 's,@QMAIL_REMOTE_USER@,${QMAIL_REMOTE_USER:Q},g'
SUBST_SED.users+=	-e 's,@QMAIL_SEND_USER@,${QMAIL_SEND_USER:Q},g'

SUBST_FILES.djbware+=	cdb_seek.c dns.c

PKG_GROUPS=		${QMAIL_QMAIL_GROUP} ${QMAIL_NOFILES_GROUP}
PKG_USERS+=		${QMAIL_ALIAS_USER}:${QMAIL_NOFILES_GROUP}
PKG_USERS+=		${QMAIL_DAEMON_USER}:${QMAIL_NOFILES_GROUP}
PKG_USERS+=		${QMAIL_LOG_USER}:${QMAIL_NOFILES_GROUP}
PKG_USERS+=		${QMAIL_PASSWD_USER}:${QMAIL_NOFILES_GROUP}
PKG_USERS+=		${QMAIL_QUEUE_USER}:${QMAIL_QMAIL_GROUP}
PKG_USERS+=		${QMAIL_REMOTE_USER}:${QMAIL_QMAIL_GROUP}
PKG_USERS+=		${QMAIL_SEND_USER}:${QMAIL_QMAIL_GROUP}
.for user in ${PKG_USERS:C/\:.*//}
PKG_HOME.${user}=	${QMAILDIR}
.endfor
PKG_HOME.alias=		${QMAILDIR}/alias

SPECIAL_PERMS+=		${PREFIX}/bin/qmail-queue ${QMAIL_QUEUE_USER} ${QMAIL_QMAIL_GROUP} 04711
.for f in qmail-inject qmail-pop3d qmail-qmqpc qmail-qmqpd qmail-qmtpd qmail-qread qmail-qstat qmail-showctl qmail-smtpd qmail-tcpok qmail-tcpto
SPECIAL_PERMS+=		${PREFIX}/bin/${f} ${QMAIL_ROOT_USER} ${QMAIL_QMAIL_GROUP} 0755
.endfor
.for f in qmail-clean qmail-getpw qmail-local qmail-popup qmail-pw2u qmail-remote qmail-rspawn qmail-send splogger
SPECIAL_PERMS+=		${PREFIX}/bin/${f} ${QMAIL_ROOT_USER} ${QMAIL_QMAIL_GROUP} 0711
.endfor
.for f in qmail-lspawn qmail-newmrh qmail-newu qmail-start
SPECIAL_PERMS+=		${PREFIX}/bin/${f} ${QMAIL_ROOT_USER} ${QMAIL_QMAIL_GROUP} 0700
.endfor

OPSYSVARS+=		DARWINSUFX
DARWINSUFX.Darwin=	.doc
DARWINSUFX.*=		# empty

post-extract: post-extract-srs post-extract-viruscan
	${CP} ${FILESDIR}/README.pkgsrc ${WRKSRC}
.if ${OPSYS} == "Darwin"
.	for i in INSTALL SENDMAIL
	  mv ${WRKSRC}/${i} ${WRKSRC}/${i}${DARWINSUFX}
.	endfor
.endif

pre-install:
	${MKDIR} ${DESTDIR}${QMAILDIR}
	${MKDIR} ${DESTDIR}${QMAIL_QUEUE_DIR}
	# keep in sync with INSTALL:PRE-INSTALL
	${LN} -s ${DESTDIR}${EGDIR}/alias	${DESTDIR}${QMAILDIR}/alias
	${LN} -s ${DESTDIR}${PREFIX}/bin	${DESTDIR}${QMAILDIR}/bin
	${LN} -s ${DESTDIR}${EGDIR}/boot	${DESTDIR}${QMAILDIR}/boot
	${LN} -s ${DESTDIR}${EGDIR}/control	${DESTDIR}${QMAILDIR}/control
	${LN} -s ${DESTDIR}${DOCDIR}		${DESTDIR}${QMAILDIR}/doc
	${LN} -s ${DESTDIR}${PREFIX}/${PKGMANDIR} ${DESTDIR}${QMAILDIR}/man
	${LN} -s ${DESTDIR}${QMAIL_QUEUE_DIR}	${DESTDIR}${QMAILDIR}/queue
	${LN} -s ${DESTDIR}${EGDIR}/users	${DESTDIR}${QMAILDIR}/users

post-install: post-install-srs post-install-viruscan
	${INSTALL_DATA} ${WRKSRC}/README.pkgsrc ${DESTDIR}${DOCDIR}

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
