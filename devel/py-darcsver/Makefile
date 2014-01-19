# $NetBSD: Makefile,v 1.4 2014/01/19 17:51:34 wiz Exp $

DISTNAME=	darcsver-1.7.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/d/darcsver/

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	https://pypi.python.org/pypi/darcsver/
COMMENT=	Generate a version number from darcs history
LICENSE=	modified-bsd

DEPENDS+=		${PYPKGPREFIX}-expat>=0:../../textproc/py-expat

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	33 # not yet ported as of 1.7.4

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
