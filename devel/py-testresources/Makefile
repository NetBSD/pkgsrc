# $NetBSD: Makefile,v 1.9 2023/11/07 22:38:00 wiz Exp $

DISTNAME=	testresources-2.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/testresources/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/testresources
COMMENT=	Pyunit extension for managing expensive test resources
LICENSE=	apache-2.0 OR modified-bsd

DEPENDS+=	${PYPKGPREFIX}-pbr-[0-9]*:../../devel/py-pbr
DEPENDS+=	${PYPKGPREFIX}-fixtures-[0-9]*:../../devel/py-fixtures
DEPENDS+=	${PYPKGPREFIX}-testtools-[0-9]*:../../devel/py-testtools
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
