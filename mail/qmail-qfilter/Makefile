# $NetBSD: Makefile,v 1.32 2022/03/01 19:15:38 schmonz Exp $
#

DISTNAME=		qmail-qfilter-2.1
PKGREVISION=		7
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://untroubled.org/qmail-qfilter/
COMMENT=		Multi-filter front end for qmail-queue
LICENSE=		unlicense

DEPENDS+=		qmail>=1.03nb9:../../mail/qmail

REPLACE_PERL=		samples/block-long-dates			\
			samples/deny-filetypes				\
			samples/rename-filetypes

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	do-configure
SUBST_FILES.paths=	qmail-qfilter.c
SUBST_SED.paths+=	-e 's|/var/qmail|${QMAILDIR}|g'
SUBST_MESSAGE.paths=	Fixing paths.

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/examples/qmail-qfilter
BUILD_DEFS+=		QMAILDIR

DJB_MAKE_TARGETS=	NO
BUILD_TARGET=		programs

.include "../../mk/bsd.prefs.mk"

post-extract:
	${RM} -f ${WRKSRC}/COPYING

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qmail-qfilter			\
		${DESTDIR}${PREFIX}/bin
	for i in ${REPLACE_PERL}; do					\
		${INSTALL_SCRIPT} ${WRKSRC}/$${i}			\
			${DESTDIR}${PREFIX}/share/examples/qmail-qfilter; \
	done
	${INSTALL_MAN} ${WRKSRC}/qmail-qfilter.1			\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
