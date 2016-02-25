# $NetBSD: Makefile,v 1.74 2016/02/25 15:00:51 jperkin Exp $
#

DISTNAME=		${PKGNAME_NOREV}
PKGNAME=		qmail-1.03
PKGREVISION=		19
CATEGORIES=		mail
MASTER_SITES=		http://qmail.org/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://cr.yp.to/qmail.html
COMMENT=		Secure, reliable, efficient, simple, and fast MTA
LICENSE=		public-domain

DEPENDS+=		checkpassword-[0-9]*:../../sysutils/checkpassword
DEPENDS+=		daemontools-[0-9]*:../../sysutils/daemontools
DEPENDS+=		ucspi-tcp-[0-9]*:../../net/ucspi-tcp

CONFLICTS+=		courier-maildirmake-[0-9]*
CONFLICTS+=		courier-mta-[0-9]*
CONFLICTS+=		mirrordir-[0-9]*
CONFLICTS+=		mutt<=1.4.2.1nb1
CONFLICTS+=		netqmail-[0-9]*
CONFLICTS+=		pulsar<=0.1.1

NOT_FOR_UNPRIVILEGED=	yes

WRKSRC=			${WRKDIR}/${DISTNAME}

PKG_DESTDIR_SUPPORT=	destdir
USE_TOOLS+=		nroff

DJB_CONFIG_CMDS=	${ECHO} ${DESTDIR:Q}${QMAILDIR:Q} > conf-destdir
DJB_BUILD_TARGETS=	man
DJB_RESTRICTED=		no

PKG_SYSCONFSUBDIR=	qmail
OWN_DIRS+=		${PKG_SYSCONFDIR} ${PKG_SYSCONFDIR}/alias
OWN_DIRS+=		${PKG_SYSCONFDIR}/control ${PKG_SYSCONFDIR}/users
OWN_DIRS+=		${QMAILDIR} ${QMAIL_QUEUE_DIR}

DOCDIR=			${PREFIX}/share/doc/qmail
EGDIR=			${PREFIX}/share/examples/qmail
SHAREDIR=		${PREFIX}/share/qmail
PLIST_SUBST+=		DARWINSUFX=${DARWINSUFX:Q}
MESSAGE_SUBST+=		DOCDIR=${DOCDIR:Q} EGDIR=${EGDIR:Q}
FILES_SUBST+=		DOCDIR=${DOCDIR:Q} EGDIR=${EGDIR:Q}
FILES_SUBST+=		OPENSSL=${OPENSSL:Q}
FILES_SUBST+=		PKGMANDIR=${PKGMANDIR:Q} SHAREDIR=${SHAREDIR:Q}
FILES_SUBST+=		QMAILDIR=${QMAILDIR:Q}
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

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	do-configure
SUBST_FILES.paths=	README.pkgsrc
SUBST_SED.paths=	-e 's,@PKGNAME@,${PKGNAME:Q},g'
SUBST_SED.paths+=	-e 's,@PKG_INFO@,${PKG_INFO:Q},g'
SUBST_SED.paths+=	-e 's,@GREP@,${GREP:Q},g'

SUBST_FILES.djbware+=	cdb_seek.c dns.c

USERGROUP_PHASE=	configure
PKG_GROUPS=		qmail nofiles
PKG_USERS+=		alias:nofiles
PKG_USERS+=		qmaill:nofiles qmaild:nofiles qmailp:nofiles
PKG_USERS+=		qmailq:qmail qmailr:qmail qmails:qmail
.for user in ${PKG_USERS:C/\:.*//}
PKG_HOME.${user}=	${QMAILDIR}
.endfor
PKG_HOME.alias=		${QMAILDIR}/alias

QMAIL_ROOT_ONLY_READABLES=	qmail-clean qmail-getpw qmail-local qmail-popup
QMAIL_ROOT_ONLY_READABLES+=	qmail-pw2u qmail-remote qmail-rspawn qmail-send
QMAIL_ROOT_ONLY_READABLES+=	splogger
QMAIL_ROOT_ONLY_EVERYTHINGS=	qmail-lspawn qmail-newmrh qmail-newu qmail-start

SPECIAL_PERMS+=		${PREFIX}/bin/qmail-queue qmailq qmail 4555
.for f in ${QMAIL_ROOT_ONLY_READABLES}
SPECIAL_PERMS+=		${PREFIX}/bin/${f} root qmail 0711
.endfor
.for f in ${QMAIL_ROOT_ONLY_EVERYTHINGS}
SPECIAL_PERMS+=		${PREFIX}/bin/${f} root qmail 0700
.endfor

OPSYSVARS+=		DARWINSUFX
DARWINSUFX.Darwin=	.doc
DARWINSUFX.*=		# empty

post-extract: post-extract-viruscan
	${CP} ${FILESDIR}/README.pkgsrc ${WRKSRC}
.if ${OPSYS} == "Darwin"
.	for i in INSTALL SENDMAIL
	  mv ${WRKSRC}/${i} ${WRKSRC}/${i}${DARWINSUFX}
.	endfor
.endif

pre-install:
.	if ${USE_DESTDIR} != "no"
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
.	endif

post-install: post-install-viruscan
	# allow packaging as non-root, fix at install time with SPECIAL_PERMS
	${CHMOD} 0755 ${DESTDIR}${PREFIX}/bin/qmail-queue
.	for f in ${QMAIL_ROOT_ONLY_READABLES} ${QMAIL_ROOT_ONLY_EVERYTHINGS}
	  ${CHMOD} 0755 ${DESTDIR}${PREFIX}/bin/${f}
.	endfor
	# qmail's installer sets strange permissions, set them back
.	for i in bin boot
	  ${CHGRP} ${BINGRP} ${DESTDIR}${QMAILDIR}/${i}
.	endfor
.	for i in doc
	  ${CHGRP} ${SHAREGRP} ${DESTDIR}${QMAILDIR}/${i}
.	endfor
.	for i in ${MANDIRS}
	  ${CHGRP} ${MANGRP} ${DESTDIR}${QMAILDIR}/${i}
.	endfor

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
