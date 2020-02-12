# $NetBSD: Makefile,v 1.7 2020/02/12 07:56:54 adam Exp $

DISTNAME=	stevedore-1.32.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/stevedore/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/dreamhost/stevedore
COMMENT=	Manage dynamic plugins for Python applications
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-pbr>=2.1.1:../../devel/py-pbr
DEPENDS+=	${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
