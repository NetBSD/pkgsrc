# $NetBSD: Makefile,v 1.13 2022/01/04 20:53:45 wiz Exp $

DISTNAME=	traitlets-5.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/traitlets/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ipython.org/
COMMENT=	Traitlets Python config system
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

# Traitlets 5.0+ supports Python 3.7 and above, following NEP 29.
# For any earlier version of Python use traitlets 4.x
PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
