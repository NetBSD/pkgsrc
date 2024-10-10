# $NetBSD: Makefile,v 1.13 2024/10/10 07:17:47 adam Exp $

DISTNAME=	immutables-0.21
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/immutables/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/MagicStack/immutables
COMMENT=	Immutable collections
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=42:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
TEST_DEPENDS+=	${PYPKGPREFIX}-codestyle>=2.9:../../devel/py-codestyle
TEST_DEPENDS+=	${PYPKGPREFIX}-flake8>=5.0:../../devel/py-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-mypy>=0.942:../../lang/py-mypy

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
