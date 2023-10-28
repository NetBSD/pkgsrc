# $NetBSD: Makefile,v 1.12 2023/10/28 19:57:10 wiz Exp $

DISTNAME=	python-lsp-server-1.7.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
PKGREVISION=	1
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-lsp-server/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-lsp/python-lsp-server
COMMENT=	Implementation of the Language Server Protocol for Python (python-language-server fork)
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

DEPENDS+=	${PYPKGPREFIX}-jedi>=0.17.2:../../editors/py-jedi
DEPENDS+=	${PYPKGPREFIX}-lsp-jsonrpc>=1.0.0:../../textproc/py-lsp-jsonrpc
DEPENDS+=	${PYPKGPREFIX}-pluggy>=1.0.0:../../devel/py-pluggy
DEPENDS+=	${PYPKGPREFIX}-docstring-to-markdown-[0-9]*:../../textproc/py-docstring-to-markdown
DEPENDS+=	${PYPKGPREFIX}-ujson>=3.0.0:../../textproc/py-ujson
DEPENDS+=	${PYPKGPREFIX}-setuptools>=39.0.0:../../devel/py-setuptools

# optional dependencies
DEPENDS+=	${PYPKGPREFIX}-autopep8>=1.6.0:../../devel/py-autopep8
DEPENDS+=	${PYPKGPREFIX}-flake8>=5.0.0:../../devel/py-flake8
DEPENDS+=	${PYPKGPREFIX}-mccabe>=0.7.0:../../devel/py-mccabe
DEPENDS+=	${PYPKGPREFIX}-codestyle>=2.9.0:../../devel/py-codestyle
DEPENDS+=	${PYPKGPREFIX}-docstyle>=6.3.0:../../devel/py-docstyle
DEPENDS+=	${PYPKGPREFIX}-flakes>=2.5.0:../../devel/py-flakes
DEPENDS+=	${PYPKGPREFIX}-pylint>=2.5.0:../../devel/py-pylint
DEPENDS+=	${PYPKGPREFIX}-rope>=1.2.0:../../devel/py-rope
DEPENDS+=	${PYPKGPREFIX}-toml-[0-9]*:../../textproc/py-toml
DEPENDS+=	${PYPKGPREFIX}-whatthepatch>=1.0.2:../../devel/py-whatthepatch
DEPENDS+=	${PYPKGPREFIX}-websockets>=10.3:../../www/py-websockets
DEPENDS+=	${PYPKGPREFIX}-yapf-[0-9]*:../../devel/py-yapf

TEST_DEPENDS+=	${PYPKGPREFIX}-pylint>=2.5.0:../../devel/py-pylint
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
TEST_DEPENDS+=	${PYPKGPREFIX}-pandas-[0-9]*:../../math/py-pandas
TEST_DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
TEST_DEPENDS+=	${PYPKGPREFIX}-qt5-[0-9]*:../../x11/py-qt5
TEST_DEPENDS+=	${PYPKGPREFIX}-flaky-[0-9]*:../../devel/py-flaky

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

SUBST_CLASSES+=		pylint
SUBST_FILES.pylint+=	test/plugins/test_pylint_lint.py
SUBST_STAGE.pylint=	pre-build
SUBST_MESSAGE.pylint=	Fix pylint executable name.
SUBST_SED.pylint=	-e "s/'pylint'$$/'pylint-${PYVERSSUFFIX}'/"

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pylsp pylsp-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
