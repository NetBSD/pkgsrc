# $NetBSD: Makefile,v 1.10 2026/04/01 12:31:04 adam Exp $

DISTNAME=	vulture-2.16
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=v/vulture/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/jendrikseipp/vulture
COMMENT=	Find dead code
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli>=1.1.0:../../textproc/py-tomli
.endif

pre-build:
	${RM} -fr ${WRKSRC}/dev

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
