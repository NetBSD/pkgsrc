# $NetBSD: Makefile,v 1.6 2024/08/25 10:19:16 wiz Exp $

DISTNAME=	jaraco_context-6.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/./}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jaraco_context/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jaraco/jaraco.context
COMMENT=	Context managers
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=1.15.0:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
TEST_DEPENDS+=	${PYPKGPREFIX}-portend-[0-9]*:../../net/py-portend

USE_LANGUAGES=	# none

WHEEL_NAME=	${DISTNAME:S/_/./}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
