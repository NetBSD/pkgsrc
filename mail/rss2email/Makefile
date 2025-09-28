# $NetBSD: Makefile,v 1.62 2025/09/28 15:15:01 schmonz Exp $

DISTNAME=		${GITHUB_PROJECT}-3.14
PKGREVISION=		4
CATEGORIES=		mail python
MASTER_SITES=		${MASTER_SITE_GITHUB:=rss2email/}
GITHUB_PROJECT=		rss2email
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://github.com/rss2email/rss2email/
COMMENT=		Get RSS feeds emailed to you
LICENSE=		gnu-gpl-v2

TOOL_DEPENDS+=		${PYPKGPREFIX}-poetry-core>=2.2.1:../../devel/py-poetry-core

DEPENDS+=		${PYPKGPREFIX}-feedparser>=6.0.11:../../textproc/py-feedparser
DEPENDS+=		${PYPKGPREFIX}-html2text>=2014.4.5:../../textproc/py-html2text

PYTHON_VERSIONS_INCOMPATIBLE=	27

REPLACE_PYTHON=		test/test.py

INSTALLATION_DIRS=	${PKGMANDIR}/man1

do-test:
	cd ${WRKSRC} && env PYTHONPATH=.:${PREFIX}/share/html2text ./test/test.py

post-install:
	set -e; cd ${WRKSRC};						\
	${INSTALL_MAN} r2e.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
