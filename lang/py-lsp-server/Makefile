# $NetBSD: Makefile,v 1.16 2024/03/17 14:04:39 wiz Exp $

DISTNAME=	python-lsp-server-1.10.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-lsp-server/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-lsp/python-lsp-server
COMMENT=	Implementation of the Language Server Protocol for Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61.2.0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.4.3:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-docstring-to-markdown-[0-9]*:../../textproc/py-docstring-to-markdown
DEPENDS+=	${PYPKGPREFIX}-jedi>=0.17.2:../../editors/py-jedi
DEPENDS+=	${PYPKGPREFIX}-lsp-jsonrpc>=1.0.0:../../textproc/py-lsp-jsonrpc
DEPENDS+=	${PYPKGPREFIX}-pluggy>=1.0.0:../../devel/py-pluggy
DEPENDS+=	${PYPKGPREFIX}-ujson>=3.0.0:../../textproc/py-ujson
# all
DEPENDS+=	${PYPKGPREFIX}-autopep8>=2.0.4:../../devel/py-autopep8
DEPENDS+=	${PYPKGPREFIX}-codestyle>=2.11.0:../../devel/py-codestyle
DEPENDS+=	${PYPKGPREFIX}-docstyle>=6.3.0:../../devel/py-docstyle
DEPENDS+=	${PYPKGPREFIX}-flake8>=7:../../devel/py-flake8
DEPENDS+=	${PYPKGPREFIX}-flakes>=3.2.0:../../devel/py-flakes
DEPENDS+=	${PYPKGPREFIX}-mccabe>=0.7.0:../../devel/py-mccabe
DEPENDS+=	${PYPKGPREFIX}-pylint>=2.5.0:../../devel/py-pylint
DEPENDS+=	${PYPKGPREFIX}-rope>=1.11.0:../../devel/py-rope
DEPENDS+=	${PYPKGPREFIX}-yapf>=0.33.0:../../devel/py-yapf
DEPENDS+=	${PYPKGPREFIX}-whatthepatch>=1.0.2:../../devel/py-whatthepatch
# websockets
DEPENDS+=	${PYPKGPREFIX}-websockets>=10.3:../../www/py-websockets
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-flaky-[0-9]*:../../devel/py-flaky
TEST_DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
TEST_DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
TEST_DEPENDS+=	${PYPKGPREFIX}-pandas-[0-9]*:../../math/py-pandas
TEST_DEPENDS+=	${PYPKGPREFIX}-qt5-[0-9]*:../../x11/py-qt5
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pylsp pylsp-${PYVERSSUFFIX} || ${TRUE}

# for tests, some use 'python'
.include "../../lang/python/tool.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
