# $NetBSD: Makefile,v 1.14 2023/06/18 12:10:23 adam Exp $

DISTNAME=	zope.schema-6.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/zope.s/ZopeS/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zope.schema/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zopefoundation/zope.schema
COMMENT=	Zope Interface extension for defining data schemas
LICENSE=	zpl-2.1

DEPENDS+=	${PYPKGPREFIX}-zope.event-[0-9]*:../../devel/py-zope.event
DEPENDS+=	${PYPKGPREFIX}-zope.interface>=5.0.0:../../devel/py-zope.interface
TEST_DEPENDS+=	${PYPKGPREFIX}-zope.i18nmessageid-[0-9]*:../../devel/py-zope.i18nmessageid
TEST_DEPENDS+=	${PYPKGPREFIX}-zope.testrunner-[0-9]*:../../devel/py-zope.testrunner
TEST_DEPENDS+=	${PYPKGPREFIX}-zope.testing-[0-9]*:../../devel/py-zope.testing

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
