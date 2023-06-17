# $NetBSD: Makefile,v 1.1 2023/06/17 18:28:31 wiz Exp $

DISTNAME=	zope.component-6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zope.component/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zopefoundation/zope.component
COMMENT=	Zope Component Architecture
LICENSE=	zpl-2.1

DEPENDS+=	${PYPKGPREFIX}-zope.event>=0:../../devel/py-zope.event
DEPENDS+=	${PYPKGPREFIX}-zope.hookable>=4.2.0:../../devel/py-zope.hookable
DEPENDS+=	${PYPKGPREFIX}-zope.interface>=5.3:../../devel/py-zope.interface
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=0:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

# still doesn't really work
TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
