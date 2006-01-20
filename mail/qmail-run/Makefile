# $NetBSD: Makefile,v 1.15 2006/01/20 23:47:42 joerg Exp $
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
NO_BUILD=		yes

INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL
FILES_SUBST+=		QMAIL_QUEUE_EXTRA=${QMAIL_QUEUE_EXTRA:Q}
FILES_SUBST+=		PKGNAME=${PKGNAME:Q}
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

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKDIR}/mailer.conf  ${WRKDIR}/qmail-procmail
SUBST_FILES.paths+=	${WRKDIR}/qmail-qfilter-queue
SUBST_FILES.paths+=	${WRKDIR}/qmail-qread-client
SUBST_SED.paths+=	-e 's,@LOCALBASE@,${LOCALBASE},g'
SUBST_SED.paths+=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.paths+=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g'
SUBST_SED.paths+=	-e 's,@ECHO@,${ECHO},g'
SUBST_SED.paths+=	-e 's,@SORT@,${SORT},g'
SUBST_SED.paths+=	-e 's,@CAT@,${CAT},g'
SUBST_SED.paths+=	-e 's,@SH@,${SH},g'
SUBST_SED.paths+=	-e 's,@SED@,${SED},g'
SUBST_SED.paths+=	-e 's,@PKGNAME@,${PKGNAME},g'
SUBST_STAGE.paths=	post-patch

post-extract:
	for f in README.pkgsrc mailer.conf; do				\
	    ${CP} ${FILESDIR}/$$f ${WRKDIR}/$$f;			\
	done
	for f in qmail-procmail qmail-qfilter-queue qmail-qread-client; do \
	    ${CP} ${FILESDIR}/$$f.sh ${WRKDIR}/$$f;			\
	done

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/qmail-procmail ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/qmail-qfilter-queue ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/qmail-qread-client ${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/README.pkgsrc ${PREFIX}/share/doc/qmail-run
	${INSTALL_DATA} ${WRKDIR}/mailer.conf ${PREFIX}/share/examples/qmail-run

.include "../../mk/bsd.pkg.mk"
