# $NetBSD: Makefile,v 1.7 2025/05/28 04:51:03 adam Exp $

DISTNAME=	hatch_vcs-0.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hatch-vcs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ofek/hatch-vcs
COMMENT=	Hatch plugin for versioning with your preferred VCS
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.1.0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=8.2.0:../../devel/py-setuptools_scm

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
