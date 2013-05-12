# $NetBSD: Makefile,v 1.1 2013/05/12 19:55:42 cheusov Exp $

DISTNAME=	oauth2-1.5.211
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python security www
MASTER_SITES=	http://pypi.python.org/packages/source/o/oauth/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pypi.python.org/pypi/oauth/
COMMENT=	Python OAuth2 library
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-httplib2>=0.7.7:../../www/py-httplib2

PYDISTUTILSPKG=	yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
