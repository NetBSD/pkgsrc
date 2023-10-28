# $NetBSD: Makefile,v 1.4 2023/10/28 19:57:00 wiz Exp $

DISTNAME=	flit_scm-1.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/flit-scm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/WillDaSilva/flit_scm
COMMENT=	PEP 518 build backend that uses setuptools_scm
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.5:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=6.4:../../devel/py-setuptools_scm

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli-[0-9]*:../../textproc/py-tomli
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
