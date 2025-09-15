# $NetBSD: Makefile,v 1.20 2025/09/15 12:12:14 adam Exp $

DISTNAME=	zope_testrunner-8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/./}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zope.testrunner/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zopefoundation/zope.testrunner
COMMENT=	Zope testrunner script
LICENSE=	zpl-2.1

DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-zope.exceptions-[0-9]*:../../devel/py-zope.exceptions
DEPENDS+=	${PYPKGPREFIX}-zope.interface-[0-9]*:../../devel/py-zope.interface
TEST_DEPENDS+=	${PYPKGPREFIX}-zope.testing-[0-9]*:../../devel/py-zope.testing

USE_LANGUAGES=	# none

TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} zope-testrunner zope-testrunner-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
