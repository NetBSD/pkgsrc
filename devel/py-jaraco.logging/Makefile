# $NetBSD: Makefile,v 1.2 2024/11/11 07:28:12 wiz Exp $

DISTNAME=	jaraco.logging-3.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jaraco.logging/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jaraco/jaraco.logging
COMMENT=	Quickly solicit log level info from command-line parameters
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.4.1:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-tempora-[0-9]*:../../time/py-tempora

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
