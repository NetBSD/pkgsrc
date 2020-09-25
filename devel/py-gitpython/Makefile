# $NetBSD: Makefile,v 1.2 2020/09/25 08:25:13 adam Exp $

DISTNAME=	GitPython-3.1.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gitpython/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gitpython-developers/GitPython
COMMENT=	Python Git Library
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-gitdb>=4.0.1:../../devel/py-gitdb

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
