# $NetBSD: Makefile,v 1.10 2025/03/05 10:24:28 wiz Exp $

DISTNAME=	keyrings_alt-5.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/./}
PKGREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=k/keyrings.alt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jaraco/keyrings.alt
COMMENT=	Alternate keyring implementations
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=75.8.2:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.4.1:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-jaraco.classes-[0-9]*:../../devel/py-jaraco.classes
DEPENDS+=	${PYPKGPREFIX}-jaraco.context-[0-9]*:../../devel/py-jaraco.context
TEST_DEPENDS+=	${PYPKGPREFIX}-cryptodome-[0-9]*:../../security/py-cryptodome
TEST_DEPENDS+=	${PYPKGPREFIX}-keyring>=20:../../security/py-keyring
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
