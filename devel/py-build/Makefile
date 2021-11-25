# $NetBSD: Makefile,v 1.1 2021/11/25 21:18:28 wiz Exp $

DISTNAME=	build-0.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/build/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pypa/build
COMMENT=	Simple, correct PEP517 package builder
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-pep517-[0-9]*:../../devel/py-pep517
DEPENDS+=	${PYPKGPREFIX}-tomli-[0-9]*:../../textproc/py-tomli
DEPENDS+=	${PYPKGPREFIX}-colorama-[0-9]*:../../comms/py-colorama

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"

.if ${PYPKGPREFIX} == "py36" || ${PYPKGPREFIX} == "py37"
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata-[0-9]*:../../devel/py-importlib-metadata
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
