# $NetBSD: Makefile,v 1.8 2024/08/10 06:24:24 wiz Exp $

DISTNAME=	pytest-shutil-1.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-shutil/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/manahl/pytest-plugins
COMMENT=	Unix shell and environment tools for py.test
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-contextlib2-[0-9]*:../../devel/py-contextlib2
DEPENDS+=	${PYPKGPREFIX}-execnet-[0-9]*:../../devel/py-execnet
DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
DEPENDS+=	${PYPKGPREFIX}-path.py-[0-9]*:../../devel/py-path.py
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-termcolor-[0-9]*:../../devel/py-termcolor

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
