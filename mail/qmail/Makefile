# $NetBSD: Makefile,v 1.35 2005/05/07 21:37:42 schmonz Exp $
#

DISTNAME=		netqmail-1.05
PKGNAME=		qmail-1.03
PKGREVISION=		10
CATEGORIES=		mail
MASTER_SITES=		http://qmail.org/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://cr.yp.to/qmail.html
COMMENT=		Secure, reliable, efficient, simple, and fast MTA

DEPENDS+=		checkpassword-[0-9]*:../../sysutils/checkpassword
DEPENDS+=		daemontools-[0-9]*:../../sysutils/daemontools
DEPENDS+=		qmail-users>=1.0:../../mail/qmail-users
DEPENDS+=		ucspi-tcp-[0-9]*:../../net/ucspi-tcp

CONFLICTS+=		courier-maildirmake-[0-9]*
CONFLICTS+=		mirrordir-[0-9]*
CONFLICTS+=		mutt<=1.4.2.1nb1
CONFLICTS+=		netqmail-[0-9]*
CONFLICTS+=		pulsar<=0.1.1

.if defined(PKG_PHASE) && ${PKG_PHASE} == "extract"
WRKSRC=			${WRKDIR}/${DISTNAME}
.else
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
.endif

PKG_INSTALLATION_TYPES=	overwrite pkgviews


DJB_BUILD_TARGETS= 	man

DJB_RESTRICTED=		YES
NO_PACKAGE=		"needs work to function properly as a binary package"

USE_PKGINSTALL=		yes
DEINSTALL_EXTRA_TMPL+=	${PKGDIR}/DEINSTALL
INSTALL_EXTRA_TMPL+=	${PKGDIR}/INSTALL
MAKE_DIRS+=		${PKG_SYSCONFDIR} ${PKG_SYSCONFDIR}/alias
MAKE_DIRS+=		${PKG_SYSCONFDIR}/control ${DOCDIR}
MAKE_DIRS+=		${PKG_SYSCONFDIR}/users
OWN_DIRS+=		${QMAILDIR} ${QMAIL_QUEUE_DIR}
PKG_SYSCONFSUBDIR=	qmail

DOCDIR=			${PREFIX}/share/doc/qmail
EGDIR=			${PREFIX}/share/examples/qmail
SHAREDIR=		${PREFIX}/share/qmail
MESSAGE_SUBST+=		DOCDIR=${DOCDIR} EGDIR=${EGDIR}
FILES_SUBST+=		DOCDIR=${DOCDIR} EGDIR=${EGDIR} SHAREDIR=${SHAREDIR}
FILES_SUBST+=		QMAILDIR=${QMAILDIR} QMAIL_QUEUE_DIR=${QMAIL_QUEUE_DIR}
FILES_SUBST+=		QMAIL_QUEUE_EXTRA=${QMAIL_QUEUE_EXTRA}
FILES_SUBST+=		VIRUSCAN_SIGS_SRCFILE=${VIRUSCAN_SIGS_SRCFILE}
FILES_SUBST+=		PKGNAME=${PKGNAME}

PLIST_SRC=		${PKGDIR}/PLIST

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

.include "options.mk"

BUILD_DEFS+=		QMAILDIR QMAIL_QUEUE_DIR QMAIL_QUEUE_EXTRA

.if !empty(QMAIL_QUEUE_DIR:M${QMAILDIR}/*)
PKG_FAIL_REASON+=	"QMAIL_QUEUE_DIR must not be under ${QMAILDIR}"
.endif

.if !empty(QMAIL_QUEUE_EXTRA)
QUEUE_EXTRA=		"T${QMAIL_QUEUE_EXTRA}\\0"
QUEUE_EXTRALEN_cmd=	${EXPR} `${ECHO_N} ${QMAIL_QUEUE_EXTRA} | ${WC} -c` + 2
SUBST_CLASSES+=		logging
SUBST_STAGE.logging=	do-configure
SUBST_FILES.logging=	extra.h
SUBST_SED.logging=	-e 's|0|${QUEUE_EXTRALEN_cmd:sh}|g'
SUBST_SED.logging+=	-e 's|""|${QUEUE_EXTRA}|g'
SUBST_MESSAGE.logging=	"Setting QUEUE_EXTRA."
.endif

post-extract:
	${_PKG_SILENT}${_PKG_DEBUG}extract_file=${PKGNAME_NOREV}.tar.gz;\
	export extract_file; cd ${WRKSRC}; ${EXTRACT_CMD};		\
	${MV} ${PKGNAME_NOREV} ..; ${MV} ${DISTNAME}.patch ..

post-build:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/README.pkgsrc            \
		> ${WRKDIR}/README.pkgsrc

post-install:
	# qmail's installer sets strange permissions; set them back
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
