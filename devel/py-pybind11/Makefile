# $NetBSD: Makefile,v 1.31 2026/03/15 16:55:55 tnn Exp $

DISTNAME=	pybind11-3.0.2
PKGREVISION=	1
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

pre-build:
	${RM} -f ${WRKSRC}/include/pybind11/detail/holder_caster_foreign_helpers.h.orig

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pybind11-config pybind11-config-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
