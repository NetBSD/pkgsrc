# $NetBSD: Makefile,v 1.12 2017/01/01 14:43:34 wiz Exp $

DISTNAME=	jersey-0.1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jersey/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pypi.python.org/pypi/jersey
COMMENT=	Framework for building Twisted Python command-line interfaces
LICENSE=	modified-bsd

#BUILD_DEPENDS+=	${PYPKGPREFIX}-twisted>=10.0.0:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-twisted>=10.0.0:../../net/py-twisted

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-twisted

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
