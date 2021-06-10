# $NetBSD: Makefile,v 1.7 2021/06/10 05:47:11 adam Exp $

DISTNAME=	traitlets-5.0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/traitlets/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ipython.org/
COMMENT=	Traitlets Python config system
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-ipython_genutils-[0-9]*:../../devel/py-ipython_genutils

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
