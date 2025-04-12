# $NetBSD: Makefile,v 1.13 2025/04/12 21:10:59 adam Exp $

DISTNAME=	pytest_subtests-0.14.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//:S/_/-/}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-subtests/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pytest-dev/pytest-subtests
COMMENT=	Unittest subTest() support and subtests fixture
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=6.2.3:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-attrs>=19.2.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-test>=7.4:../../devel/py-test

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
