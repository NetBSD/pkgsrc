# $NetBSD: Makefile,v 1.14 2024/11/11 07:28:44 wiz Exp $

DISTNAME=	immutables-0.21
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/immutables/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/MagicStack/immutables
COMMENT=	Immutable collections
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=42:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-codestyle>=2.9:../../devel/py-codestyle
TEST_DEPENDS+=	${PYPKGPREFIX}-flake8>=5.0:../../devel/py-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-mypy>=0.942:../../lang/py-mypy

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
