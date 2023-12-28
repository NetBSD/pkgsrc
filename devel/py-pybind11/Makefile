# $NetBSD: Makefile,v 1.18 2023/12/28 13:29:26 thor Exp $

DISTNAME=	pybind11-2.11.1
PATCHLEVEL=	1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pybind11/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pybind/pybind11
COMMENT=	Seamless operability between C++11 and Python
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pybind11-config pybind11-config-${PYVERSSUFFIX} || ${TRUE}

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
