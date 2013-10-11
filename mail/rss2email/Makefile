# $NetBSD: Makefile,v 1.34 2013/10/11 17:16:44 schmonz Exp $
#

DISTNAME=		v3.7
PKGNAME=		rss2email-3.7
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}archive/
DIST_SUBDIR=		rss2email

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://github.com/wking/rss2email/
COMMENT=		Get RSS feeds emailed to you
LICENSE=		gnu-gpl-v2

DEPENDS+=		${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
DEPENDS+=		${PYPKGPREFIX}-feedparser>=5.0.1:../../textproc/py-feedparser
DEPENDS+=		${PYPKGPREFIX}-html2text>=3.0.1:../../textproc/py-html2text

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

PYTHON_VERSIONS_INCLUDE_3X=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	26 27

PYDISTUTILSPKG=		yes
PY_PATCHPLIST=		yes
REPLACE_PYTHON=		test/test.py

SUBST_CLASSES+=		bin
SUBST_STAGE.bin=	do-configure
SUBST_FILES.bin=	rss2email/main.py
SUBST_SED.bin=		-e 's|@LOCALBASE@|${LOCALBASE}|g'

INSTALLATION_DIRS=	${PKGMANDIR}/man1

do-test:
	cd ${WRKSRC} && env PYTHONPATH=.:${LOCALBASE}/share/html2text ./test/test.py

post-install:
	set -e; cd ${WRKSRC};						\
	${INSTALL_MAN} r2e.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
