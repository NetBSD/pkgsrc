# $NetBSD: Makefile,v 1.1 2022/01/17 09:51:28 wiz Exp $

DISTNAME=	astropy-helpers-4.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/astropy-helpers/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/astropy/astropy-helpers/
COMMENT=	Tools for Astropy package
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-sphinx-astropy-[0-9]*:../../textproc/py-sphinx-astropy

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
