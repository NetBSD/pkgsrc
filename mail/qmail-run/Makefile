# $NetBSD: Makefile,v 1.73 2019/06/19 17:49:13 schmonz Exp $
#

DISTNAME=		qmail-run-20190619
CATEGORIES=		mail
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		schmonz@NetBSD.org
COMMENT=		Configures qmail to receive and deliver mail
LICENSE=		2-clause-bsd

DEPENDS+=		greetdelay-[0-9]*:../../mail/greetdelay
DEPENDS+=		greylisting-spp-[0-9]*:../../mail/greylisting-spp
DEPENDS+=		pkg_alternatives-[0-9]*:../../pkgtools/pkg_alternatives
DEPENDS+=		qmail>=1.03nb42:../../mail/qmail
DEPENDS+=		qmail-acceptutils>=20181228:../../mail/qmail-acceptutils
DEPENDS+=		qmail-qfilter>1.5nb1:../../mail/qmail-qfilter
DEPENDS+=		qmail-rejectutils>=20181230:../../mail/qmail-rejectutils
DEPENDS+=		qmail-spp-spf-[0-9]*:../../mail/qmail-spp-spf

WRKSRC=			${WRKDIR}
NO_BUILD=		yes
NO_CHECKSUM=		yes

FILES_SUBST+=		QMAIL_DAEMON_USER=${QMAIL_DAEMON_USER:Q}
FILES_SUBST+=		QMAIL_LOG_USER=${QMAIL_LOG_USER:Q}
FILES_SUBST+=		QMAIL_SEND_USER=${QMAIL_SEND_USER:Q}
FILES_SUBST+=		PKGNAME=${PKGNAME:Q}
FILES_SUBST+=		UCSPI_SSL_USER=${UCSPI_SSL_USER:Q}
FILES_SUBST+=		UCSPI_SSL_GROUP=${UCSPI_SSL_GROUP:Q}
MESSAGE_SUBST+=		PKG_SYSCONFBASE=${PKG_SYSCONFBASE:Q}
RCD_SCRIPTS=		qmail qmailofmipd qmailpop3d qmailqread qmailsend qmailsmtpd

PKG_SYSCONFSUBDIR=	qmail

EGDIR=			share/examples/qmail-run
.for f in defaultdelivery fixsmtpio signatures rcptchecks \
	ofmipfilters smtpfilters \
	pop3capabilities smtpcapabilities smtpplugins \
	concurrencyincoming concurrencypop3 concurrencysubmission
CONF_FILES+=		${PREFIX}/${EGDIR}/${f} \
			${PKG_SYSCONFDIR}/control/${f}
.endfor
TCPRULESDIR=		${PKG_SYSCONFDIR}/control/tcprules
OWN_DIRS+=		${TCPRULESDIR}
.for f in ofmip pop3 smtp
CONF_FILES+=		${PREFIX}/${EGDIR}/tcprules-${f} \
			${TCPRULESDIR}/${f}
.endfor
GREYLISTDIR=		${PKG_SYSCONFDIR}/control/greylist
OWN_DIRS_PERMS+=	${GREYLISTDIR} ${QMAIL_DAEMON_USER} ${QMAIL_QMAIL_GROUP} 775
CONF_FILES_PERMS+=	${PREFIX}/${EGDIR}/greylist-database ${GREYLISTDIR}/database ${QMAIL_DAEMON_USER} ${QMAIL_QMAIL_GROUP} 664
.for f in exemptrcpthosts exemptrcpts
CONF_FILES+=		${PREFIX}/${EGDIR}/greylist-${f} \
			${GREYLISTDIR}/${f}
.endfor

INSTALLATION_DIRS=	bin share/doc/qmail-run ${EGDIR}
BUILD_DEFS+=		QMAIL_DAEMON_USER QMAIL_LOG_USER QMAIL_SEND_USER
BUILD_DEFS+=		QMAIL_QMAIL_GROUP PKG_SYSCONFBASE
BUILD_DEFS+=		UCSPI_SSL_USER UCSPI_SSL_GROUP

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	mailer.conf README.pkgsrc
SUBST_FILES.paths+=	greylisting-spp-wrapper ofmipd-with-user-cdb
SUBST_FILES.paths+=	qmail-isspam-* qmail-procmail qmail-qread-client
SUBST_FILES.paths+=	rcptchecks ofmipfilters smtpfilters smtpplugins tcprules-*
SUBST_VARS.paths=	PKGNAME PKG_SYSCONFDIR PREFIX RCD_SCRIPTS_DIR
SUBST_VARS.paths+=	CAT ECHO GREP SED SH SORT TRUE

post-extract:
	for f in README.pkgsrc mailer.conf \
		defaultdelivery fixsmtpio signatures rcptchecks \
		ofmipfilters smtpfilters \
		pop3capabilities smtpcapabilities smtpplugins \
		concurrencyincoming concurrencypop3 concurrencysubmission \
		tcprules-ofmip tcprules-pop3 tcprules-smtp; do \
		${CP} ${FILESDIR}/$$f ${WRKDIR}/$$f; \
	done; \
	for f in greylisting-spp-wrapper ofmipd-with-user-cdb \
		qmail-isspam-rspamd qmail-isspam-spamassassin \
		qmail-procmail qmail-qread-client; do \
		${CP} ${FILESDIR}/$$f.sh ${WRKDIR}/$$f; \
	done

do-install:
	for f in greylisting-spp-wrapper ofmipd-with-user-cdb \
		qmail-isspam-rspamd qmail-isspam-spamassassin \
		qmail-procmail qmail-qread-client; do \
		${INSTALL_SCRIPT} ${WRKDIR}/$$f ${DESTDIR}${PREFIX}/bin; \
	done
	${INSTALL_DATA} ${WRKDIR}/README.pkgsrc \
		${DESTDIR}${PREFIX}/share/doc/qmail-run
	for f in defaultdelivery fixsmtpio signatures rcptchecks \
		ofmipfilters smtpfilters \
		pop3capabilities smtpcapabilities smtpplugins \
		concurrencyincoming concurrencypop3 concurrencysubmission \
		tcprules-ofmip tcprules-pop3 tcprules-smtp; do \
		${INSTALL_DATA} ${WRKDIR}/$${f} \
			${DESTDIR}${PREFIX}/${EGDIR}; \
	done; \
	for f in database exemptrcpthosts exemptrcpts; do \
		${TOUCH} ${DESTDIR}${PREFIX}/${EGDIR}/greylist-$${f}; \
	done; \
	${INSTALL_DATA} ${WRKDIR}/mailer.conf \
		${DESTDIR}${PREFIX}/${EGDIR}

.include "../../mk/bsd.pkg.mk"
