# $NetBSD: Makefile,v 1.4 2015/12/05 21:25:57 adam Exp $

DISTNAME=	oauth2-1.5.211
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python security www
MASTER_SITES=	http://pypi.python.org/packages/source/o/oauth/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/oauth2/
COMMENT=	Python OAuth2 library
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-httplib2>=0.7.7:../../www/py-httplib2

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # not yet ported as of 1.5.211

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
