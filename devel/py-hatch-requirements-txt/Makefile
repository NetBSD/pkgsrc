# $NetBSD: Makefile,v 1.1 2026/05/27 10:52:47 markd Exp $

DISTNAME=	hatch_requirements_txt-0.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hatch-requirements-txt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/repo-helper/hatch-requirements-txt
COMMENT=	Hatch plugin to read project dependencies from requirements.txt
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.1.0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-packaging>=21.3:../../devel/py-packaging

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
