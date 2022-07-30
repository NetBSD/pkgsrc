# $NetBSD: Makefile,v 1.8 2022/07/30 20:21:32 tnn Exp $

DISTNAME=	build-0.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
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

USE_PKG_RESOURCES=	yes

.include "../../lang/python/pyversion.mk"

.if ${PYPKGPREFIX} == "py37"
#DEPENDS+=	${PYPKGPREFIX}-importlib-metadata-[0-9]*:../../devel/py-importlib-metadata
BROKEN+=		"circular dependency"
.endif

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pyproject-build pyproject-build-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
