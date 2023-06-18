# $NetBSD: Makefile,v 1.12 2023/06/18 12:10:23 adam Exp $

DISTNAME=	zope.configuration-4.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/zope.c/ZopeC/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zope.configuration/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zopefoundation/zope.configuration
COMMENT=	Zope Configuration Markup Language
LICENSE=	zpl-2.1

DEPENDS+=	${PYPKGPREFIX}-zope.i18nmessageid-[0-9]*:../../devel/py-zope.i18nmessageid
DEPENDS+=	${PYPKGPREFIX}-zope.interface-[0-9]*:../../devel/py-zope.interface
DEPENDS+=	${PYPKGPREFIX}-ZopeSchema>=4.9.0:../../devel/py-ZopeSchema
TEST_DEPENDS+=	${PYPKGPREFIX}-manuel-[0-9]*:../../textproc/py-manuel
TEST_DEPENDS+=	${PYPKGPREFIX}-zope.testrunner-[0-9]*:../../devel/py-zope.testrunner
TEST_DEPENDS+=	${PYPKGPREFIX}-zope.testing-[0-9]*:../../devel/py-zope.testing

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
