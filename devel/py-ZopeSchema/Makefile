# $NetBSD: Makefile,v 1.4 2020/06/08 13:24:35 adam Exp $

DISTNAME=	zope.schema-6.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/zope.s/ZopeS/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zope.schema/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zopefoundation/zope.schema
COMMENT=	Zope Interface extension for defining data schemas
LICENSE=	zpl-2.1

DEPENDS+=	${PYPKGPREFIX}-ZopeEvent-[0-9]*:../../devel/py-ZopeEvent
DEPENDS+=	${PYPKGPREFIX}-ZopeInterface>=5.0.0:../../devel/py-ZopeInterface
DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-ZopeI18NMessageid-[0-9]*:../../devel/py-ZopeI18NMessageid
TEST_DEPENDS+=	${PYPKGPREFIX}-ZopeTestrunner-[0-9]*:../../devel/py-ZopeTestrunner
TEST_DEPENDS+=	${PYPKGPREFIX}-zope.testing-[0-9]*:../../devel/py-zope.testing

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
