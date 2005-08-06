# $NetBSD: Makefile,v 1.9 2005/08/06 20:25:54 schmonz Exp $
#

DISTNAME=		rss2email-${RVER}
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}
EXTRACT_SUFX=		.py
DISTFILES=		r2e-${SVER}.sh ${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=		html2text-${HVER}.py

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://www.aaronsw.com/2002/rss2email/
COMMENT=		Get RSS feeds emailed to you

DEPENDS+=		${PYPKGPREFIX}-feedparser-[0-9]*:../../textproc/py-feedparser

SVER=			2.0
RVER=			2.55
HVER=			2.23

SITES_html2text-${HVER}.py=	http://www.aaronsw.com/2002/html2text/

DIST_SUBDIR=		${PKGNAME_NOREV}

NO_BUILD=		yes
PYTHON_PATCH_SCRIPTS=	*.py

SUBST_CLASSES+=		bin
SUBST_STAGE.bin=	do-configure
SUBST_FILES.bin=	r2e
SUBST_SED.bin=		-e 's|@PREFIX@|${PREFIX}|g'
SUBST_SED.bin+=		-e 's|@PYTHONBIN@|${PYTHONBIN}|g'

SHAREDIR=		${PREFIX}/share/rss2email
EGDIR=			${PREFIX}/share/examples/rss2email
INSTALLATION_DIRS=	bin man/man1

do-extract:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${CP} -R ${DISTDIR}/${DIST_SUBDIR} ${WRKSRC};			\
	cd ${WRKSRC};							\
	${MV} rss2email-${RVER}.py rss2email.py;			\
	${MV} html2text-${HVER}.py html2text.py;			\
	${MV} r2e-${SVER}.sh r2e

do-install:
	cd ${WRKSRC} &&							\
	${INSTALL_SCRIPT_DIR} ${SHAREDIR};				\
	${INSTALL_SCRIPT} rss2email.py ${SHAREDIR};			\
	${INSTALL_SCRIPT} html2text.py ${SHAREDIR};			\
	${INSTALL_DATA_DIR} ${EGDIR};					\
	${INSTALL_DATA} config.py ${EGDIR};				\
	${INSTALL_MAN} r2e.1 ${PREFIX}/man/man1;			\
	${INSTALL_SCRIPT} r2e ${PREFIX}/bin

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
