# $NetBSD: Makefile,v 1.25 2023/01/02 12:05:42 adam Exp $

DISTNAME=	ZConfig-3.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=Z/ZConfig/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zopefoundation/ZConfig
COMMENT=	Configuration library
LICENSE=	zpl-2.1

TEST_DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils
TEST_DEPENDS+=	${PYPKGPREFIX}-manuel-[0-9]*:../../textproc/py-manuel
TEST_DEPENDS+=	${PYPKGPREFIX}-zope.exceptions-[0-9]*:../../devel/py-zope.exceptions
TEST_DEPENDS+=	${PYPKGPREFIX}-ZopeTestrunner-[0-9]*:../../devel/py-ZopeTestrunner

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} zconfig zconfig-${PYVERSSUFFIX} && \
	${MV} zconfig_schema2html zconfig_schema2html-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} zope-testrunner --test-path=src

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
