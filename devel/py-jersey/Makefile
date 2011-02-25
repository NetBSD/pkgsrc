# $NetBSD: Makefile,v 1.2 2011/02/25 09:47:21 wiz Exp $
#

DISTNAME=	jersey-0.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/j/jersey/

MAINTAINER=	ver@NetBSD.org
HOMEPAGE=	http://pypi.python.org/pypi/jersey
COMMENT=	Framework for building Twisted Python command-line interfaces
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_ACCEPTED= 27 26

BUILD_DEPENDS+=	${PYPKGPREFIX}-twisted>=10.0.0:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-twisted>=10.0.0:../../net/py-twisted

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
