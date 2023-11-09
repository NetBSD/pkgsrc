# $NetBSD: Makefile,v 1.6 2023/11/09 14:30:19 adam Exp $

DISTNAME=	hatch_vcs-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hatch-vcs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ofek/hatch-vcs
COMMENT=	Hatch plugin for versioning with your preferred VCS
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.1.0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=6.4.0:../../devel/py-setuptools_scm

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
