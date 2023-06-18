# $NetBSD: Makefile,v 1.12 2023/06/18 05:39:37 adam Exp $

DISTNAME=	zope.testrunner-5.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/zope.t/ZopeT/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zope.testrunner/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zopefoundation/zope.testrunner
COMMENT=	Zope testrunner script
LICENSE=	zpl-2.1

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-zope.exceptions-[0-9]*:../../devel/py-zope.exceptions
DEPENDS+=	${PYPKGPREFIX}-zope.interface-[0-9]*:../../devel/py-zope.interface
TEST_DEPENDS+=	${PYPKGPREFIX}-zope.testing-[0-9]*:../../devel/py-zope.testing

PYTHON_VERSIONS_INCOMPATIBLE=	27

TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib
USE_PKG_RESOURCES=	yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
