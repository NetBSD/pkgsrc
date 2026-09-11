# $NetBSD: Makefile,v 1.1 2026/09/11 10:23:52 adam Exp $

DISTNAME=	diff_cover-10.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/diff-cover/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Bachmann1234/diff-cover
COMMENT=	Run coverage and linting reports on diffs
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=0:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-chardet>=3.0.0:../../converters/py-chardet
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.7.1:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-pluggy>=0.13.1:../../devel/py-pluggy
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.19.1:../../textproc/py-pygments
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=6.1.1:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-datadir>=1.5.0:../../devel/py-test-datadir
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=3.14.0:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=3.6.1:../../devel/py-test-xdist

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	diff-cover diff-quality

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
