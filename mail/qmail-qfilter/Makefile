# $NetBSD: Makefile,v 1.9 2005/03/13 03:25:44 schmonz Exp $
#

DISTNAME=		qmail-qfilter-2.0
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://untroubled.org/qmail-qfilter/
COMMENT=		Multi-filter front end for qmail-queue

DEPENDS+=		qmail>=1.03nb9:../../mail/qmail

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes
OWN_DIRS_PERMS+=	${QMAIL_QFILTER_TMPDIR} qmaild ${ROOT_GROUP} 700

REPLACE_PERL=		samples/block-long-dates			\
			samples/deny-filetypes				\
			samples/rename-filetypes

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	do-configure
SUBST_FILES.paths=	qmail-qfilter.c
SUBST_SED.paths=	-e 's|/tmp|${QMAIL_QFILTER_TMPDIR}|g'
SUBST_SED.paths+=	-e 's|/var/qmail|${QMAILDIR}|g'
SUBST_MESSAGE.paths=	"Fixing paths."

INSTALLATION_DIRS=	bin man man/man1 share/examples/qmail-qfilter

.include "../../mk/bsd.prefs.mk"

do-configure:
	${ECHO} ${CC:Q} ${CFLAGS:Q} > ${WRKSRC}/conf-cc
	${ECHO} ${CC:Q} ${_STRIPFLAG_CC} > ${WRKSRC}/conf-ld
	${ECHO} ${PREFIX}/bin > ${WRKSRC}/conf-bin
	${ECHO} ${PREFIX}/man > ${WRKSRC}/conf-man
	${ECHO} ${PREFIX}/include/bglibs > ${WRKSRC}/conf-bgincs
	${ECHO} ${PREFIX}/lib/bglibs > ${WRKSRC}/conf-bglibs

do-install:
	cd ${WRKSRC} && ./installer && ./instcheck
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/qmail-qfilter
	for i in ${REPLACE_PERL}; do					\
		${INSTALL_SCRIPT} ${WRKSRC}/$${i}			\
			${PREFIX}/share/examples/qmail-qfilter;		\
	done

.include "../../devel/bglibs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
