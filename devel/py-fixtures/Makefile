# $NetBSD: Makefile,v 1.13 2024/11/11 07:28:08 wiz Exp $

DISTNAME=	fixtures-4.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/fixtures/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/fixtures/
COMMENT=	Fixtures, reusable state for writing clean tests and more
LICENSE=	apache-2.0 OR modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-pbr>=0:../../devel/py-pbr
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
# needs py-testtools for testing, but that depends on this
#TEST_DEPENDS+=	${PYPKGPREFIX}-testtools-[0-9]*:../../devel/py-testtools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
