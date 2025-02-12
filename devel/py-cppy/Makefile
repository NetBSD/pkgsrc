# $NetBSD: Makefile,v 1.6 2025/02/12 11:31:07 adam Exp $

DISTNAME=	cppy-1.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cppy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/nucleic/cppy
COMMENT=	C++ headers for C extension development
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.4.3:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-setuptools>=61.2:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
