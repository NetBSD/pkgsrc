# $NetBSD: Makefile,v 1.9 2022/01/12 06:46:15 adam Exp $

DISTNAME=	pybind11-2.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pybind11/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pybind/pybind11
COMMENT=	Seamless operability between C++11 and Python
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=	yes

USE_PKG_RESOURCES=	yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
