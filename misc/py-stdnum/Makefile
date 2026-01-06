# $NetBSD: Makefile,v 1.29 2026/01/06 09:10:26 adam Exp $

DISTNAME=	python_stdnum-2.2
PKGNAME=	${DISTNAME:S/python_/${PYPKGPREFIX}-/}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-stdnum/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://arthurdejong.org/python-stdnum
COMMENT=	Python module to handle standardized numbers and codes
LICENSE=	gnu-lgpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
