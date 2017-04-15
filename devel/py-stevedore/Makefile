# $NetBSD: Makefile,v 1.2 2017/04/15 12:30:07 leot Exp $

DISTNAME=	stevedore-1.21.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/stevedore/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/dreamhost/stevedore
COMMENT=	Manage dynamic plugins for Python applications
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-pbr>=2.0.0:../../devel/py-pbr
DEPENDS+=	${PYPKGPREFIX}-six>=1.9.0:../../lang/py-six

USE_LANGUAGES=			# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
