# $NetBSD: Makefile,v 1.31 2023/12/01 19:37:47 adam Exp $

DISTNAME=	amqp-5.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/amqp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://amqp.readthedocs.io/
COMMENT=	Low-level AMQP client for Python
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-vine>=5.0.0:../../devel/py-vine
TEST_DEPENDS+=	${PYPKGPREFIX}-test-rerunfailures>=6.0:../../devel/py-test-rerunfailures
TEST_DEPENDS+=	${PYPKGPREFIX}-test-sugar>=0.9.1:../../devel/py-test-sugar

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
