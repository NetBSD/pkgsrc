# $NetBSD: Makefile,v 1.56 2008/02/19 13:59:05 schmonz Exp $
#

DISTNAME=		netqmail-1.05
PKGNAME=		qmail-1.03
PKGREVISION=		13
CATEGORIES=		mail
MASTER_SITES=		http://qmail.org/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://cr.yp.to/qmail.html
COMMENT=		Secure, reliable, efficient, simple, and fast MTA

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

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
USE_TOOLS+=		nroff

DJB_BUILD_TARGETS=	man
DJB_RESTRICTED=		no

MAKE_DIRS+=		${PKG_SYSCONFDIR} ${PKG_SYSCONFDIR}/alias
MAKE_DIRS+=		${PKG_SYSCONFDIR}/control ${PKG_SYSCONFDIR}/users
OWN_DIRS+=		${QMAILDIR} ${QMAIL_QUEUE_DIR}
PKG_SYSCONFSUBDIR=	qmail

DOCDIR=			${PREFIX}/share/doc/qmail
EGDIR=			${PREFIX}/share/examples/qmail
SHAREDIR=		${PREFIX}/share/qmail
MESSAGE_SUBST+=		DOCDIR=${DOCDIR:Q} EGDIR=${EGDIR:Q}
FILES_SUBST+=		DOCDIR=${DOCDIR:Q} EGDIR=${EGDIR:Q} SHAREDIR=${SHAREDIR:Q}
FILES_SUBST+=		QMAILDIR=${QMAILDIR:Q} QMAIL_QUEUE_DIR=${QMAIL_QUEUE_DIR:Q}
FILES_SUBST+=		QMAIL_QUEUE_EXTRA=${QMAIL_QUEUE_EXTRA:Q}
FILES_SUBST+=		VIRUSCAN_SIGS_SRCFILE=${VIRUSCAN_SIGS_SRCFILE:Q}
FILES_SUBST+=		PKGNAME=${PKGNAME:Q}

SETUP_PROGRAMS=		dnsfq dnsip dnsptr hostname install ipmeprint
SETUP_SCRIPTS=		config config-fast

MANDIRS=		man
.for i in cat man
.  for j in 1 5 7 8
MANDIRS+=		man/${i}${j}
.  endfor
.endfor
INSTALLATION_DIRS=	bin ${MANDIRS}
INSTALLATION_DIRS+=	share/doc/qmail share/examples/qmail/boot share/qmail

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

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKDIR}/README.pkgsrc
SUBST_SED.paths+=	-e 's,@PKGNAME@,${PKGNAME:Q},g'
SUBST_SED.paths+=	-e 's,@PKG_INFO@,${PKG_INFO:Q},g'
SUBST_SED.paths+=	-e 's,@GREP@,${GREP:Q},g'
SUBST_STAGE.paths=	post-patch

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

SPECIAL_PERMS+=		${PREFIX}/bin/qmail-queue qmailq qmail 4555

# extract the qmail tarball that was inside the netqmail distfile
post-extract:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	extract_file=${WRKDIR}/${DISTNAME}/${PKGNAME_NOREV}.tar.gz;	\
	cd ${WRKDIR} && ${EXTRACT_CMD}
	${CP} ${FILESDIR}/README.pkgsrc ${WRKDIR}/README.pkgsrc

post-install:
	# qmail's installer sets strange permissions, set them back
.	if (${PKG_INSTALLATION_TYPE} == "overwrite")
.	  for i in bin boot
	    ${CHGRP} ${BINGRP} ${QMAILDIR}/${i}
.	  endfor
.	  for i in doc
	    ${CHGRP} ${SHAREGRP} ${QMAILDIR}/${i}
.	  endfor
.	  for i in ${MANDIRS}
	    ${CHGRP} ${MANGRP} ${QMAILDIR}/${i}
.	  endfor
.	endif

	${INSTALL_DATA} ${WRKDIR}/README.pkgsrc ${DOCDIR}

	${INSTALL_PROGRAM_DIR} ${SHAREDIR}/setup
	for i in ${SETUP_PROGRAMS}; do					\
		${INSTALL_PROGRAM} ${WRKSRC}/$$i ${SHAREDIR}/setup;	\
	done
	for i in ${SETUP_SCRIPTS}; do					\
		${INSTALL_SCRIPT} ${WRKSRC}/$$i ${SHAREDIR}/setup;	\
	done

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
