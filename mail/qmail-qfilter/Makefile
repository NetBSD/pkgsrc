# $NetBSD: Makefile,v 1.10 2005/03/23 00:51:10 schmonz Exp $
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

BUILD_TARGET=		all

DJB_RESTRICTED=		NO
BGWARE_INSTALLER=	YES
DJB_CONFIG_CMDS=	${ECHO} ${PREFIX}/include/bglibs > ${WRKSRC}/conf-bgincs;
DJB_CONFIG_CMDS+=	${ECHO} ${PREFIX}/lib/bglibs > ${WRKSRC}/conf-bglibs

.include "../../mk/bsd.prefs.mk"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/qmail-qfilter
	for i in ${REPLACE_PERL}; do					\
		${INSTALL_SCRIPT} ${WRKSRC}/$${i}			\
			${PREFIX}/share/examples/qmail-qfilter;		\
	done

.include "../../devel/bglibs/buildlink3.mk"
.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
