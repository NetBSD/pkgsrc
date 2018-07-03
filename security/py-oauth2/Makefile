# $NetBSD: Makefile,v 1.9 2018/07/03 05:03:32 adam Exp $

DISTNAME=	oauth2-1.5.211
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python security www
MASTER_SITES=	${MASTER_SITE_PYPI:=o/oauth2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/joestump/python-oauth2
COMMENT=	Python OAuth2 library
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-httplib2>=0.7.7:../../www/py-httplib2

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # not yet ported as of 1.5.211

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
