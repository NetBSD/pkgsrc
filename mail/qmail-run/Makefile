# $NetBSD: Makefile,v 1.1.1.1 2004/08/02 03:59:21 schmonz Exp $
#

DISTNAME=		qmail-run-20040801
CATEGORIES=		mail
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		schmonz@NetBSD.org
COMMENT=		Configures qmail to receive and deliver mail

DEPENDS_QMAIL=		{qmail>=1.03nb8,netqmail>=1.05nb1}:../../mail/qmail
DEPENDS+=		${DEPENDS_QMAIL}
.if !exists(/usr/sbin/mailwrapper)
DEPENDS+=		mailwrapper-[0-9]*:../../mail/mailwrapper
.endif
.if !exists(/etc/rc.subr)
DEPENDS+=		rc.subr-[0-9]*:../../pkgtools/rc.subr
.endif

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}
NO_CHECKSUM=		# defined

USE_PKGINSTALL=		yes
INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL
FILES_SUBST+=		QMAIL_QUEUE_EXTRA=${QMAIL_QUEUE_EXTRA}
RCD_SCRIPTS=		qmail qmailqread qmailpop3d qmailsend qmailsmtpd

INSTALLATION_DIRS=	bin share/doc/qmail-run share/examples/qmail-run

.include "../../mk/bsd.prefs.mk"

# Detect the PKG_SYSCONFDIR of the installed qmail or netqmail, so we
# can create config files there and refer to them from rc.d scripts.
.if !empty(PHASES_AFTER_EXTRACT:M${PKG_PHASE})
INSTALLED_QMAIL!= \
	dep=`${PKG_BEST_EXISTS} ${DEPENDS_QMAIL:C/:.*$//:Q:S/\ / /g}`;	\
	case "$$dep" in							\
	"")	${ECHO} "qmail_not_found_" ;;				\
	*)	${ECHO} "$$dep" ;;					\
	esac
.  if empty(INSTALLED_QMAIL:M*_not_found_)
.    if !defined(PKG_SYSCONFDIR.qmail-run)
PKG_SYSCONFDIR.qmail-run!= \
	${PKG_INFO} -qB ${INSTALLED_QMAIL} |				\
		${SED} -n '/^PKG_SYSCONFDIR=/s|^PKG_SYSCONFDIR=[ 	]*||p'
.    endif
.  endif
.endif

do-build:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/README.pkgsrc		\
		> ${WRKDIR}/README.pkgsrc
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/mailer.conf		\
		> ${WRKDIR}/mailer.conf
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/qmail-qread-client.sh	\
		> ${WRKDIR}/qmail-qread-client

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/qmail-qread-client ${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/README.pkgsrc ${PREFIX}/share/doc/qmail-run
	${INSTALL_DATA} ${WRKDIR}/mailer.conf ${PREFIX}/share/examples/qmail-run

.include "../../mk/bsd.pkg.mk"
