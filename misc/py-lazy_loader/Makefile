# $NetBSD: Makefile,v 1.5 2024/11/11 07:28:44 wiz Exp $

DISTNAME=	lazy_loader-0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lazy_loader/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/scientific-python/lazy_loader
COMMENT=	Load subpackages and functions on demand
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61.2:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=4.1:../../devel/py-test-cov

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
