# $NetBSD: Makefile,v 1.10 2022/02/05 14:53:33 adam Exp $

DISTNAME=	pybind11-2.9.1
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
