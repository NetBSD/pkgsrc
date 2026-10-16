# $NetBSD: Makefile,v 1.6 2026/10/16 17:46:58 adam Exp $

DISTNAME=	flit_scm-1.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/flit-scm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/WillDaSilva/flit_scm
COMMENT=	PEP 518 build backend that uses setuptools_scm
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=6.4:../../devel/py-setuptools_scm

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
