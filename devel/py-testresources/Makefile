# $NetBSD: Makefile,v 1.12 2025/04/28 07:44:56 adam Exp $

DISTNAME=	testresources-2.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/testresources/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/testresources
COMMENT=	Pyunit extension for managing expensive test resources
LICENSE=	apache-2.0 OR modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-pbr>=1.8:../../devel/py-pbr
DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-fixtures-[0-9]*:../../devel/py-fixtures
DEPENDS+=	${PYPKGPREFIX}-testtools-[0-9]*:../../devel/py-testtools

PYTHON_VERSIONS_INCOMPATIBLE=	39 310 # py-sphinx via py-pbr

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
