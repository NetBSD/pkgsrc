# $NetBSD: Makefile,v 1.3 2024/09/16 09:24:06 adam Exp $

DISTNAME=	amaranth-0.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/amaranth/}

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://github.com/amaranth-lang/amaranth
COMMENT=	Toolchain for developing hardware based on synchronous digital logic
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-pdm_backend>=2.3.0:../../devel/py-pdm_backend
DEPENDS+=	${PYPKGPREFIX}-jinja2>=3.0:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-jschon>=0.11.1:../../textproc/py-jschon
DEPENDS+=	${PYPKGPREFIX}-pyvcd>=0.2.2:../../devel/py-pyvcd

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 309
DEPENDS+=	${PYPKGPREFIX}-importlib-resources-[0-9]*:../../devel/py-importlib-resources
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
