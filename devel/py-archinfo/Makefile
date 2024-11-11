# $NetBSD: Makefile,v 1.10 2024/11/11 07:28:00 wiz Exp $

.include "../../devel/py-angr/version.mk"

DISTNAME=	archinfo-${ANGR_VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/archinfo/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/angr/archinfo
COMMENT=	Classes with architecture-specific information
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-backports.strenum>=1.2.8:../../devel/py-backports.strenum
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
