# $NetBSD: Makefile,v 1.16 2019/10/16 16:37:52 adam Exp $

DISTNAME=	pytest-mock-1.11.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-mock/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pytest-dev/pytest-mock
COMMENT=	Thin-wrapper around the mock package for easier use with py.test
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-test>=2.7:../../devel/py-test
BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
.endif

do-test:
	cd ${WRKSRC} && py.test-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
