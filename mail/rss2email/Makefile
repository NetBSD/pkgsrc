# $NetBSD: Makefile,v 1.38 2014/05/17 16:10:46 wiz Exp $

DISTNAME=		v3.8
PKGNAME=		rss2email-3.8
PKGREVISION=		2
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}archive/
DIST_SUBDIR=		rss2email

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://github.com/wking/rss2email/
COMMENT=		Get RSS feeds emailed to you
LICENSE=		gnu-gpl-v2

DEPENDS+=		${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
DEPENDS+=		${PYPKGPREFIX}-feedparser>=5.0.1:../../textproc/py-feedparser
DEPENDS+=		${PYPKGPREFIX}-html2text>=2014.4.5:../../textproc/py-html2text

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

PYTHON_VERSIONS_INCOMPATIBLE=	26 27

PYDISTUTILSPKG=		yes
PY_PATCHPLIST=		yes
REPLACE_PYTHON=		test/test.py

INSTALLATION_DIRS=	${PKGMANDIR}/man1

do-test:
	cd ${WRKSRC} && env PYTHONPATH=.:${LOCALBASE}/share/html2text ./test/test.py

post-install:
	set -e; cd ${WRKSRC};						\
	${INSTALL_MAN} r2e.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
