# $NetBSD: Makefile,v 1.28 2025/07/14 10:54:52 wiz Exp $

DISTNAME=	pybind11-3.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pybind11/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pybind/pybind11
COMMENT=	Seamless operability between C++11 and Python
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-scikit-build-core>=0.11.2:../../devel/py-scikit-build-core
TOOL_DEPENDS+=	cmake>=3.15:../../devel/cmake

USE_LANGUAGES=	c c++

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pybind11-config pybind11-config-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
