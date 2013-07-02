# $NetBSD: Makefile,v 1.32 2013/07/02 01:13:30 schmonz Exp $
#

R2EVER=			3.5
DISTNAME=		rss2email-${R2EVER}
CATEGORIES=		mail
MASTER_SITES=		-http://nodeload.github.com/wking/rss2email/tar.gz/v${R2EVER}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://github.com/wking/rss2email/
COMMENT=		Get RSS feeds emailed to you
LICENSE=		gnu-gpl-v2

DEPENDS+=		${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
DEPENDS+=		${PYPKGPREFIX}-feedparser>=5.0.1:../../textproc/py-feedparser
DEPENDS+=		${PYPKGPREFIX}-html2text>=3.0.1:../../textproc/py-html2text

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
