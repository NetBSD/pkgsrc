# $NetBSD: Makefile,v 1.3 2020/06/08 14:09:55 adam Exp $

DISTNAME=	zope.testrunner-5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/zope.t/ZopeT/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zope.testrunner/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zopefoundation/zope.testrunner
COMMENT=	Zope testrunner script
LICENSE=	zpl-2.1

DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-zope.exceptions-[0-9]*:../../devel/py-zope.exceptions
DEPENDS+=	${PYPKGPREFIX}-ZopeInterface-[0-9]*:../../devel/py-ZopeInterface
TEST_DEPENDS+=	${PYPKGPREFIX}-zope.testing-[0-9]*:../../devel/py-zope.testing

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
