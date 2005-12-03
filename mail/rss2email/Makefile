# $NetBSD: Makefile,v 1.10 2005/12/03 00:49:36 schmonz Exp $
#

DISTNAME=		rss2email-${RVER}
PKGREVISION=		1
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}
EXTRACT_SUFX=		.py
DISTFILES=		r2e-${SVER}.sh ${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://www.aaronsw.com/2002/rss2email/
COMMENT=		Get RSS feeds emailed to you

DEPENDS+=		${PYPKGPREFIX}-feedparser-[0-9]*:../../textproc/py-feedparser
DEPENDS+=		${PYPKGPREFIX}-html2text-[0-9]*:../../textproc/py-html2text

SVER=			2.0
RVER=			2.55

DIST_SUBDIR=		${PKGNAME_NOREV}

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
INSTALLATION_DIRS=	bin man/man1

do-extract:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${CP} -R ${DISTDIR}/${DIST_SUBDIR} ${WRKSRC};			\
	cd ${WRKSRC};							\
	${MV} rss2email-${RVER}.py rss2email.py;			\
	${MV} r2e-${SVER}.sh r2e

do-install:
	cd ${WRKSRC} &&							\
	${INSTALL_SCRIPT_DIR} ${SHAREDIR};				\
	${INSTALL_SCRIPT} rss2email.py ${SHAREDIR};			\
	${INSTALL_DATA_DIR} ${EGDIR};					\
	${INSTALL_DATA} config.py ${EGDIR};				\
	${INSTALL_MAN} r2e.1 ${PREFIX}/man/man1;			\
	${INSTALL_SCRIPT} r2e ${PREFIX}/bin

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
