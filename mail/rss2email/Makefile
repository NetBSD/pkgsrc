# $NetBSD: Makefile,v 1.7 2005/06/16 06:58:08 jlam Exp $
#

DISTNAME=		rss2email-${RVER}
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}
EXTRACT_SUFX=		.py
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} r2e html2text-${HVER}.py

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://www.aaronsw.com/2002/rss2email/
COMMENT=		Get RSS feeds emailed to you

DEPENDS+=		${PYPKGPREFIX}-feedparser-[0-9]*:../../textproc/py-feedparser

RVER=			2.54
HVER=			2.21

SITES_html2text-${HVER}.py=	http://www.aaronsw.com/2002/html2text/

DIST_SUBDIR=		${PKGNAME_NOREV}

NO_BUILD=		# defined
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
	${CP} -R ${DISTDIR}/${DIST_SUBDIR} ${WRKSRC}

do-install:
	cd ${WRKSRC} &&							\
	${INSTALL_SCRIPT_DIR} ${SHAREDIR};				\
	${INSTALL_SCRIPT} rss2email-${RVER}.py ${SHAREDIR}/rss2email.py;\
	${INSTALL_SCRIPT} html2text-${HVER}.py ${SHAREDIR}/html2text.py;\
	${INSTALL_DATA_DIR} ${EGDIR};					\
	${INSTALL_DATA} config.py ${EGDIR};				\
	${INSTALL_MAN} r2e.1 ${PREFIX}/man/man1;			\
	${INSTALL_SCRIPT} r2e ${PREFIX}/bin

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
