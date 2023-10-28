# $NetBSD: Makefile,v 1.8 2023/10/28 19:56:56 wiz Exp $

.include "../../devel/py-angr/version.mk"

DISTNAME=	archinfo-${ANGR_VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/archinfo/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/angr/archinfo
COMMENT=	Classes with architecture-specific information
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m unittest tests/*.py

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
