# $NetBSD: Makefile,v 1.29 2024/11/11 07:28:30 wiz Exp $

DISTNAME=	zconfig-4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=Z/ZConfig/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zopefoundation/ZConfig
COMMENT=	Configuration library
LICENSE=	zpl-2.1

WHEEL_NAME=	ZConfig-${PKGVERSION_NOREV}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils
TEST_DEPENDS+=	${PYPKGPREFIX}-manuel-[0-9]*:../../textproc/py-manuel
TEST_DEPENDS+=	${PYPKGPREFIX}-zope.exceptions-[0-9]*:../../devel/py-zope.exceptions
TEST_DEPENDS+=	${PYPKGPREFIX}-zope.testrunner-[0-9]*:../../devel/py-zope.testrunner

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} zconfig zconfig-${PYVERSSUFFIX} && \
	${MV} zconfig_schema2html zconfig_schema2html-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} zope-testrunner-${PYVERSSUFFIX} --test-path=src

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
