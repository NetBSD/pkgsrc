# $NetBSD: Makefile,v 1.1.1.1 2004/06/27 23:00:34 schmonz Exp $
#

DISTNAME=		rss2email-2.32
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}
EXTRACT_SUFX=		.py
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} r2e html2text-1.0.py

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://www.aaronsw.com/2002/rss2email/
COMMENT=		Get RSS feeds emailed to you

DEPENDS+=		${PYPKGPREFIX}-feedparser-[0-9]*:../../textproc/py-feedparser

SITES_html2text-1.0.py=	http://www.aaronsw.com/2002/html2text/

DIST_SUBDIR=		${PKGNAME_NOREV}

NO_BUILD=		# defined
USE_BUILDLINK3=		yes
PYTHON_PATCH_SCRIPTS=	*.py

SUBST_CLASSES+=		bin
SUBST_STAGE.bin=	do-configure
SUBST_FILES.bin=	r2e
SUBST_SED.bin=		-e 's|@PREFIX@|${PREFIX}|g'
SUBST_SED.bin+=		-e 's|@PYTHONBIN@|${PYTHONBIN}|g'

SHAREDIR=		${PREFIX}/share/rss2email
EGDIR=			${PREFIX}/share/examples/rss2email

do-extract:
	${CP} -R ${DISTDIR}/${DIST_SUBDIR} ${WRKSRC}

do-install:
	cd ${WRKSRC} &&							\
	${INSTALL_SCRIPT_DIR} ${SHAREDIR};				\
	${INSTALL_SCRIPT} rss2email-2.32.py ${SHAREDIR}/rss2email.py;	\
	${INSTALL_SCRIPT} html2text-1.0.py ${SHAREDIR}/html2text.py;	\
	${INSTALL_DATA_DIR} ${EGDIR};					\
	${INSTALL_DATA} config.py ${EGDIR};				\
	${INSTALL_MAN} r2e.1 ${PREFIX}/man/man1;			\
	${INSTALL_SCRIPT} r2e ${PREFIX}/bin

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
