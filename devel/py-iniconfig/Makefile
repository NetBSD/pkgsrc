# $NetBSD: Makefile,v 1.9 2026/10/07 05:16:47 adam Exp $

DISTNAME=	iniconfig-2.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/iniconfig/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pytest-dev/iniconfig
COMMENT=	Brain-dead simple config-ini parsing
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=77:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=8:../../devel/py-setuptools_scm

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
