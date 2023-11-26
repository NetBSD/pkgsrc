# $NetBSD: Makefile,v 1.33 2023/11/26 12:30:46 wiz Exp $

DISTNAME=	pexpect-4.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pexpect/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://pexpect.readthedocs.io/
COMMENT=	Pure Python Expect-like module
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-ptyprocess>=0.5:../../sysutils/py-ptyprocess

USE_LANGUAGES=	# none

USE_TOOLS+=	bash:test
PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
