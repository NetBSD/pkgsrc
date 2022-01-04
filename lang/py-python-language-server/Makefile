# $NetBSD: Makefile,v 1.5 2022/01/04 20:54:10 wiz Exp $

DISTNAME=	python-language-server-0.36.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-language-server/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/palantir/python-language-server
COMMENT=	Implementation of the Language Server Protocol for Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-rope>=0.10.5:../../devel/py-rope
DEPENDS+=	${PYPKGPREFIX}-flakes>=2.2.0:../../devel/py-flakes
DEPENDS+=	${PYPKGPREFIX}-flake8>=3.8.0:../../devel/py-flake8
DEPENDS+=	${PYPKGPREFIX}-mccabe>=0.6.0:../../devel/py-mccabe
DEPENDS+=	${PYPKGPREFIX}-codestyle>=2.6.0:../../devel/py-codestyle
DEPENDS+=	${PYPKGPREFIX}-docstyle>=2.0.0:../../devel/py-docstyle
DEPENDS+=	${PYPKGPREFIX}-autopep8-[0-9]*:../../devel/py-autopep8
DEPENDS+=	${PYPKGPREFIX}-yapf-[0-9]*:../../devel/py-yapf
DEPENDS+=	${PYPKGPREFIX}-jedi>=0.17:../../editors/py-jedi
DEPENDS+=	${PYPKGPREFIX}-jsonrpc-server>=0.4.0:../../textproc/py-jsonrpc-server
DEPENDS+=	${PYPKGPREFIX}-pylint>=2.5.0:../../devel/py-pylint
DEPENDS+=	${PYPKGPREFIX}-pluggy-[0-9]*:../../devel/py-pluggy

TEST_DEPENDS+=	${PYPKGPREFIX}-flaky-[0-9]*:../../devel/py-flaky
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock

PYTHON_VERSIONED_DEPENDENCIES=	test:test

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-pylint, py-parso via py-jedi

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} pyls pyls-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
