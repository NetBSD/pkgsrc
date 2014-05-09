# $NetBSD: Makefile,v 1.3 2014/05/09 07:37:18 wiz Exp $

DISTNAME=	oauth2-1.5.211
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python security www
MASTER_SITES=	http://pypi.python.org/packages/source/o/oauth/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/oauth2/
COMMENT=	Python OAuth2 library
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-httplib2>=0.7.7:../../www/py-httplib2

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 1.5.211

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
