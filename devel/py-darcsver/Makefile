# $NetBSD: Makefile,v 1.15 2022/01/04 20:52:59 wiz Exp $

DISTNAME=	darcsver-1.7.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=d/darcsver/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/darcsver/
COMMENT=	Generate a version number from darcs history
LICENSE=	modified-bsd

DEPENDS+=		${PYPKGPREFIX}-expat>=0:../../textproc/py-expat

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 1.7.4

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
