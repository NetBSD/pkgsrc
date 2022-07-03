# $NetBSD: Makefile,v 1.1 2022/07/03 12:31:48 wiz Exp $

DISTNAME=	flit_scm-1.6.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/flit-scm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/WillDaSilva/flit_scm
COMMENT=	PEP 518 build backend that uses setuptools_scm
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-flit_core-[0-9]*:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-tomli-[0-9]*:../../textproc/py-tomli

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
