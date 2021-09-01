# $NetBSD: Makefile,v 1.9 2021/09/01 18:22:05 adam Exp $

DISTNAME=	traitlets-5.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/traitlets/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ipython.org/
COMMENT=	Traitlets Python config system
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

# Traitlets 5.0+ supports Python 3.7 and above, following NEP 29.
# For any earlier version of Python use traitlets 4.x
PYTHON_VERSIONS_INCOMPATIBLE=	27 36

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
