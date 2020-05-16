# $NetBSD: Makefile,v 1.4 2020/05/16 17:38:40 adam Exp $

DISTNAME=	testresources-2.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/testresources/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/testresources
COMMENT=	Pyunit extension for managing expensive test resources
LICENSE=	apache-2.0 OR modified-bsd

DEPENDS+=	${PYPKGPREFIX}-pbr-[0-9]*:../../devel/py-pbr
DEPENDS+=	${PYPKGPREFIX}-fixtures-[0-9]*:../../devel/py-fixtures
DEPENDS+=	${PYPKGPREFIX}-testtools-[0-9]*:../../devel/py-testtools

PYTHON_VERSIONED_DEPENDENCIES=	test:test

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
