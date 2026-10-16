# $NetBSD: Makefile,v 1.11 2026/10/16 19:43:50 adam Exp $

DISTNAME=	msgspec-0.21.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/msgspec/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://jcristharif.com/msgspec/
COMMENT=	Fast serialization and validation library
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=80:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=8:../../devel/py-setuptools_scm
# toml
DEPENDS+=	${PYPKGPREFIX}-tomli_w-[0-9]*:../../textproc/py-tomli_w
# yaml
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

PYTHON_VERSIONS_INCOMPATIBLE=	311

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
