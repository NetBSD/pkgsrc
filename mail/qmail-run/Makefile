# $NetBSD: Makefile,v 1.12 2005/09/28 20:52:24 rillig Exp $
#

DISTNAME=		qmail-run-20050415
CATEGORIES=		mail
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		schmonz@NetBSD.org
COMMENT=		Configures qmail to receive and deliver mail

DEPENDS_QMAIL=		qmail>=1.03nb8:../../mail/qmail
DEPENDS+=		${DEPENDS_QMAIL}

CONFLICTS+=		qmail-qfilter-1.5nb1

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}
NO_CHECKSUM=		yes

USE_PKGINSTALL=		yes
INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL
FILES_SUBST+=		QMAIL_QUEUE_EXTRA=${QMAIL_QUEUE_EXTRA}
FILES_SUBST+=		PKGNAME=${PKGNAME}
RCD_SCRIPTS=		qmail qmailpop3d qmailqread qmailsend qmailsmtpd

INSTALLATION_DIRS=	bin share/doc/qmail-run share/examples/qmail-run

.include "../../mk/bsd.prefs.mk"

# Detect the PKG_SYSCONFDIR of the installed qmail, so we can create
# config files there and refer to them from rc.d scripts.
.if !empty(PHASES_AFTER_EXTRACT:M${PKG_PHASE})
INSTALLED_QMAIL!= ${PKG_BEST_EXISTS} ${DEPENDS_QMAIL:C/:.*$//:Q:S/\ / /g}
.  if empty(INSTALLED_QMAIL:M*_not_found_)
.    if !defined(PKG_SYSCONFDIR.qmail-run)
PKG_SYSCONFDIR.qmail-run!= ${PKG_INFO} -Q PKG_SYSCONFDIR ${INSTALLED_QMAIL}
.    endif
.  endif
.endif

do-build:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/README.pkgsrc		\
		> ${WRKDIR}/README.pkgsrc
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/mailer.conf		\
		> ${WRKDIR}/mailer.conf
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/qmail-procmail.sh	\
		> ${WRKDIR}/qmail-procmail
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/qmail-qfilter-queue.sh	\
		> ${WRKDIR}/qmail-qfilter-queue
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/qmail-qread-client.sh	\
		> ${WRKDIR}/qmail-qread-client

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/qmail-procmail ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/qmail-qfilter-queue ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/qmail-qread-client ${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/README.pkgsrc ${PREFIX}/share/doc/qmail-run
	${INSTALL_DATA} ${WRKDIR}/mailer.conf ${PREFIX}/share/examples/qmail-run

.include "../../mk/bsd.pkg.mk"
