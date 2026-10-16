# $NetBSD: Makefile,v 1.11 2026/10/16 18:16:03 adam Exp $

DISTNAME=	vulture-2.16
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=v/vulture/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/jendrikseipp/vulture
COMMENT=	Find dead code
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov

USE_LANGUAGES=	# none

pre-build:
	${RM} -fr ${WRKSRC}/dev

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
