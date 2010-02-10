# $NetBSD: Makefile,v 1.24 2010/02/10 19:17:41 joerg Exp $
#

DISTNAME=		rss2email-2.65
PKGREVISION=		1
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}
EXTRACT_SUFX=		.py

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://rss2email.infogami.com/
COMMENT=		Get RSS feeds emailed to you

DEPENDS+=		${PYPKGPREFIX}-feedparser-[0-9]*:../../textproc/py-feedparser
DEPENDS+=		${PYPKGPREFIX}-html2text-[0-9]*:../../textproc/py-html2text

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}

USE_TOOLS+=		tr
NO_BUILD=		yes
PYTHON_PATCH_SCRIPTS=	*.py

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
	tr -d '\r' < ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}		\
		> ${WRKSRC}/rss2email.py
	cd ${FILESDIR} && cp config.py r2e r2e.1 ${WRKSRC}

do-install:
	set -e; cd ${WRKSRC};						\
	${INSTALL_SCRIPT_DIR} ${DESTDIR}${SHAREDIR};			\
	${INSTALL_SCRIPT} rss2email.py ${DESTDIR}${SHAREDIR};		\
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR};				\
	${INSTALL_DATA} config.py ${DESTDIR}${EGDIR};			\
	${INSTALL_MAN} r2e.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1;	\
	${INSTALL_SCRIPT} r2e ${DESTDIR}${PREFIX}/bin

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
