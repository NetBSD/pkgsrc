# $NetBSD: Makefile,v 1.19 2020/01/03 12:33:19 adam Exp $

DISTNAME=	py-1.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/py/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://py.readthedocs.io/
COMMENT=	Library with cross-python path, ini-parsing, io, code, log facilities
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
