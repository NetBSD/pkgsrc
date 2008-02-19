# $NetBSD: Makefile,v 1.17 2008/02/19 10:33:05 schmonz Exp $
#

DISTNAME=		rss2email-2.62
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}
EXTRACT_SUFX=		.py

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://rss2email.infogami.com/
COMMENT=		Get RSS feeds emailed to you

DEPENDS+=		${PYPKGPREFIX}-feedparser-[0-9]*:../../textproc/py-feedparser
DEPENDS+=		${PYPKGPREFIX}-html2text-[0-9]*:../../textproc/py-html2text

WRKSRC=			${WRKDIR}

USE_TOOLS+=		tr
NO_BUILD=		yes
PYTHON_PATCH_SCRIPTS=	*.py
PYTHON_VERSIONS_ACCEPTED?=	24 23 22

SUBST_CLASSES+=		bin
SUBST_STAGE.bin=	do-configure
SUBST_FILES.bin=	rss2email.py r2e
SUBST_SED.bin=		-e 's|@LOCALBASE@|${LOCALBASE}|g'
SUBST_SED.bin+=		-e 's|@PREFIX@|${PREFIX}|g'
SUBST_SED.bin+=		-e 's|@PYTHONBIN@|${PYTHONBIN}|g'

SHAREDIR=		${PREFIX}/share/rss2email
EGDIR=			${PREFIX}/share/examples/rss2email
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-extract:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${TR} -d '\r' < ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}		\
		> ${WRKSRC}/rss2email.py;				\
	cd ${FILESDIR} && cp config.py r2e r2e.1 ${WRKSRC}

do-install:
	cd ${WRKSRC} &&							\
	${INSTALL_SCRIPT_DIR} ${SHAREDIR};				\
	${INSTALL_SCRIPT} rss2email.py ${SHAREDIR};			\
	${INSTALL_DATA_DIR} ${EGDIR};					\
	${INSTALL_DATA} config.py ${EGDIR};				\
	${INSTALL_MAN} r2e.1 ${PREFIX}/${PKGMANDIR}/man1;			\
	${INSTALL_SCRIPT} r2e ${PREFIX}/bin

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
