# $NetBSD: Makefile,v 1.20 2010/03/15 02:33:28 schmonz Exp $
#

DISTNAME=		qmail-qfilter-2.1
PKGREVISION=		1
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://untroubled.org/qmail-qfilter/
COMMENT=		Multi-filter front end for qmail-queue

DEPENDS+=		qmail>=1.03nb9:../../mail/qmail

PKG_DESTDIR_SUPPORT=	destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

OWN_DIRS_PERMS+=	${QMAIL_QFILTER_TMPDIR} qmaild ${ROOT_GROUP} 700

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
BUILD_DEFS+=		QMAILDIR QMAIL_QFILTER_TMPDIR

DJB_RESTRICTED=		NO
DJB_MAKE_TARGETS=	NO

.include "../../mk/bsd.prefs.mk"

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/qmail-qfilter
	for i in ${REPLACE_PERL}; do					\
		${INSTALL_SCRIPT} ${WRKSRC}/$${i}			\
			${DESTDIR}${PREFIX}/share/examples/qmail-qfilter; \
	done

.include "../../devel/bglibs/buildlink3.mk"
.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
