# $NetBSD: Makefile,v 1.25 2017/04/27 20:04:22 schmonz Exp $
#

DISTNAME=		qmail-qfilter-2.1
PKGREVISION=		4
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://untroubled.org/qmail-qfilter/
COMMENT=		Multi-filter front end for qmail-queue
LICENSE=		gnu-gpl-v2

DEPENDS+=		qmail>=1.03nb9:../../mail/qmail

OWN_DIRS_PERMS+=	${QMAIL_QFILTER_TMPDIR} ${QMAIL_DAEMON_USER} ${REAL_ROOT_GROUP} 700

REPLACE_PERL=		samples/block-long-dates			\
			samples/deny-filetypes				\
			samples/rename-filetypes

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	do-configure
SUBST_FILES.paths=	qmail-qfilter.c
SUBST_SED.paths=	-e 's|/tmp|${QMAIL_QFILTER_TMPDIR}|g'
SUBST_SED.paths+=	-e 's|/var/qmail|${QMAILDIR}|g'
SUBST_MESSAGE.paths=	Fixing paths.

INSTALLATION_DIRS=	bin man ${PKGMANDIR}/man1 share/examples/qmail-qfilter
INSTALL_ENV+=		install_prefix=${DESTDIR:Q}
BUILD_DEFS+=		QMAILDIR QMAIL_DAEMON_USER QMAIL_QFILTER_TMPDIR

DJB_RESTRICTED=		NO
DJB_MAKE_TARGETS=	NO

.include "../../mk/bsd.prefs.mk"

post-install:
	for i in ${REPLACE_PERL}; do					\
		${INSTALL_SCRIPT} ${WRKSRC}/$${i}			\
			${DESTDIR}${PREFIX}/share/examples/qmail-qfilter; \
	done

.include "../../devel/bglibs/buildlink3.mk"
.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
