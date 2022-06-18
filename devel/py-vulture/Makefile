# $NetBSD: Makefile,v 1.1 2022/06/18 22:30:01 wiz Exp $

DISTNAME=	vulture-2.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=v/vulture/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/jendrikseipp/vulture
COMMENT=	Find dead code
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-toml>=0.10.1:../../textproc/py-toml

USE_LANGUAGES=	# none

# pypi distfile does not include tests
do-test:

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
