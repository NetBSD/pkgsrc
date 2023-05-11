# $NetBSD: Makefile,v 1.7 2023/05/11 07:18:11 adam Exp $

.include "../../devel/py-angr/version.mk"

DISTNAME=	archinfo-${ANGR_VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/archinfo/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/angr/archinfo
COMMENT=	Classes with architecture-specific information
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m unittest tests/*.py

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
