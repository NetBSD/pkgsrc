# $NetBSD: Makefile,v 1.1 2020/05/18 13:36:49 wiz Exp $

DISTNAME=	python-language-server-0.32.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-language-server/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/palantir/python-language-server
COMMENT=	Implementation of the Language Server Protocol for Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-rope-[0-9]*:../../devel/py-rope
DEPENDS+=	${PYPKGPREFIX}-flakes-[0-9]*:../../devel/py-flakes
DEPENDS+=	${PYPKGPREFIX}-mccabe-[0-9]*:../../devel/py-mccabe
DEPENDS+=	${PYPKGPREFIX}-codestyle-[0-9]*:../../devel/py-codestyle
DEPENDS+=	${PYPKGPREFIX}-docstyle-[0-9]*:../../devel/py-docstyle
DEPENDS+=	${PYPKGPREFIX}-autopep8-[0-9]*:../../devel/py-autopep8
DEPENDS+=	${PYPKGPREFIX}-yapf-[0-9]*:../../devel/py-yapf
DEPENDS+=	${PYPKGPREFIX}-jedi>=0.17:../../editors/py-jedi
DEPENDS+=	${PYPKGPREFIX}-jsonrpc-server-[0-9]*:../../textproc/py-jsonrpc-server
DEPENDS+=	${PYPKGPREFIX}-pylint-[0-9]*:../../devel/py-pylint
DEPENDS+=	${PYPKGPREFIX}-pluggy-[0-9]*:../../devel/py-pluggy

TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock

PYTHON_VERSIONED_DEPENDENCIES=	test:test

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-pylint

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} pyls pyls-${PYVERSSUFFIX}

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
